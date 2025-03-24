#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>
#include <netinet/ip.h>


typedef struct s_c {
	int fd;
	unsigned int id;
	char* arr;
} t_client;

unsigned int gid = 0;
int gmax = 0, gfd = -1, gret = -1;
char gbuf[FD_SETSIZE * 8 + 1] = {0};
char* gtext[] = {
	"Wrong numbr of arguments\n",
	"Fatal error\n",
	"server: client %d just arrived\n",
	"client %d: %s\n",
	"server: client %d just left\n",
};
t_client client[FD_SETSIZE] = {0};


static void giveErro(char* str, size_t sz)
{
	write(STDERR_FILENO, str, sz);
	exit(EXIT_FAILURE);
}

static void closeAll(void)
{
	for (int i = 0; i < FD_SETSIZE; i++) {
		if (client[i].fd > 0) close(client[i].fd);
		free(client[i].arr);
	}
	close(gfd);
}

static void serverMsg(char* msg, unsigned int id)
{
	char text[32 + 4] = {0};
	size_t sz = 0;

	sprintf(text, msg, id);
	sz = strlen(text);
	for (int i = 0; i < FD_SETSIZE; i++)
		if (client[i].fd > 0 && client[i].id != id) send(client[i].fd, text, sz, MSG_NOSIGNAL);
}

static void sendMsg(char* msg, size_t sz, unsigned int id)
{
	for (int i = 0; i < FD_SETSIZE; i++)
		if (client[i].fd > 0 && client[i].id != id) send(client[i].fd, msg, sz, MSG_NOSIGNAL);
}


void startSock(char* str_port);
void startLoop(void);
void readMsg(t_client* c);
void editSend(t_client* c);


int main(int argc, char** argv)
{
	if (argc < 2) giveErro( gtext[0], strlen(gtext[0]) );

	startSock(argv[1]);
	startLoop();
}

void startSock(char* str_port)
{
	gfd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
	if (gfd == -1) giveErro( gtext[1], strlen(gtext[1]) );

	struct sockaddr_in sock;

	sock.sin_family = AF_INET;
	sock.sin_port = htons( atoi(str_port) );
	sock.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	if (bind( gfd, (struct sockaddr*)&sock, sizeof(struct sockaddr_in) ) == -1) {
		close(gfd);
		giveErro( gtext[1], strlen(gtext[1]) );
	}

	if (listen(gfd, FD_SETSIZE) == -1) {
		close(gfd);
		giveErro( gtext[1], strlen(gtext[1]) );
	}
	for (int i = 0; i < FD_SETSIZE; i++) {
		client[i].arr = calloc(FD_SETSIZE * FD_SETSIZE + 1, sizeof(char));
		if (client[i].arr == 0) {
			for (int j = 0; j < i; j++) free(client[j].arr);
			close(gfd);
			giveErro( gtext[1], strlen(gtext[1]) );
		}
	}
}

void startLoop(void)
{
	fd_set read;

	do {
		gmax = gfd;
		FD_ZERO(&read);
		FD_SET(gfd, &read);
		for (int i = 0; i < FD_SETSIZE; i++) {
			if (client[i].fd > 0) {
				FD_SET(client[i].fd, &read);
				if (gmax < client[i].fd) gmax = client[i].fd;
			}
		}

		gret = select(gmax + 1, &read, 0, 0, 0);

		if (gret == -1) continue;

		if (FD_ISSET(gfd, &read)) {
			int fd = -1, i = 0;

			fd = accept(gfd, 0, 0);
			if (fd < 0) continue;

			for (i = 0; i < FD_SETSIZE; i++) {
				if (client[i].fd < 1) {
					client[i].fd = fd;
					client[i].id = gid++;
					serverMsg(gtext[2], client[i].id);
					break;
				}
			}
			if (i == FD_SETSIZE) close(fd);
		}

		for (int i = 0; i < FD_SETSIZE; i++)
			if (FD_ISSET(client[i].fd, &read)) readMsg(&client[i]);
	} while ("feito por adantas-");
}

void readMsg(t_client* c)
{
	gret = recv(c->fd, gbuf, FD_SETSIZE * 8, 0);

	if (gret < 1) {
		serverMsg(gtext[4], c->id);
		close(c->fd);
		c->fd = -1;
		bzero(c->arr, FD_SETSIZE * FD_SETSIZE + 1);
		return;
	}
	gbuf[gret] = 0;

	strcat(c->arr, gbuf);
	if (strstr(gbuf, "\n") != 0) editSend(c);
}

void editSend(t_client* c)
{
	char* rabaeni[2] = {0};
	char* text = 0;

	text = calloc( strlen(c->arr) + 12 + 4, sizeof(char) );
	if (text == 0) {
		closeAll();
		giveErro( gtext[1], strlen(gtext[1]) );
	}
	*rabaeni = strstr(c->arr, "\n");
	rabaeni[1] = c->arr;
	while (*rabaeni != 0) {
		**rabaeni = 0;
		sprintf(text, gtext[3], c->id, rabaeni[1]);
		sendMsg(text, strlen(text), c->id);
		rabaeni[1] = (*rabaeni) + 1;
		*rabaeni = strstr(rabaeni[1], "\n");
	}
/* OLD VERSION IF
	if (rabaeni[1][0] != 0) {
		strcpy(text, rabaeni[1]);
		bzero(c->arr, FD_SETSIZE * FD_SETSIZE + 1);
		strcpy(c->arr, text);
	}
*/
	if (rabaeni[1][0] != 0) strcpy(c->arr, rabaeni[1]);
	else bzero(c->arr, FD_SETSIZE * FD_SETSIZE + 1);
	free(text);
}
