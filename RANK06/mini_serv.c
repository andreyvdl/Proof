#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <strings.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/ip.h>

typedef struct
{
	int	fd;
	int	id;
} t_client;


fd_set g_r;
t_client g_client[FD_SETSIZE] = {0};
int g_id = 0, g_fd = -1, g_ret = -1, g_max = 2;
const char* g_def[] = {
	"Wrong number of arguments\n",
	"Fatal error\n",
	"server: client %d just arrived\n",
	"server: client %d just left\n",
	"client %d: %s\n",
	"client %d: \n"
};


void loop(void);
void getMsgs(void);
void formatMsg(char* buf, char* msg, int id);


static void closeAll(void)
{
	for (int i = 0; i < FD_SETSIZE; i++) {
		if (g_client[i].fd > 0)
			close(g_client[i].fd);
	}
	close(g_fd);
}

static void sendMsg(char* msg, size_t sz, int id)
{
	for (int i = 0; i < FD_SETSIZE; i++) {
		if (g_client[i].fd > 0 && g_client[i].id != id)
			send(g_client[i].fd, msg, sz, MSG_NOSIGNAL);
	}
}

static void enterAndExit(int id, int pos)
{
	char msg[33] = {0};

	sprintf(msg, g_def[pos], id);
	sendMsg(msg, strlen(msg), id);
}


int main(int argc, char** argv)
{
	struct sockaddr_in sockaddr = {0};

	if (argc < 2) {
		write(STDERR_FILENO, g_def[0], strlen(g_def[0]));
		exit(EXIT_FAILURE);
	}

	g_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
	if (g_fd == -1) {
		write(STDERR_FILENO, g_def[1], strlen(g_def[1]));
		exit(EXIT_FAILURE);
	}

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(atoi(argv[1]));
	sockaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	if (bind(g_fd, (struct sockaddr*)&sockaddr, sizeof(struct sockaddr_in)) == -1) {
		write(STDERR_FILENO, g_def[1], strlen(g_def[1]));
		close(g_fd);
		exit(EXIT_FAILURE);
	}

	if (listen(g_fd, FD_SETSIZE) == -1) {
		write(STDERR_FILENO, g_def[1], strlen(g_def[1]));
		close(g_fd);
		exit(EXIT_FAILURE);
	}

	loop();
	return EXIT_SUCCESS;
}

void loop(void)
{
	do {
		g_max = g_fd;
		FD_ZERO(&g_r);
		FD_SET(g_fd, &g_r);
		for (int i = 0; i < FD_SETSIZE; i++) {
			if (g_client[i].fd > 0) {
				FD_SET(g_client[i].fd, &g_r);
				if (g_client[i].fd > g_max)
					g_max = g_client[i].fd;
			}
		}

		g_ret = select(g_max + 1, &g_r, 0, 0, 0);
// Apartir daqui tudo só aceita conexão e responde, então śo alocação resulta em
// Fatal error

		if (g_ret == -1)
			continue;

		if (FD_ISSET(g_fd, &g_r)) {
			int new = accept(g_fd, 0, 0);

			if (new == -1)
				continue;
			for (int i = 0; i < FD_SETSIZE; i++) {
				if (g_client[i].fd < 1) {
					g_client[i].fd = new;
					g_client[i].id = g_id++;
					enterAndExit(g_client[i].id, 2);
					break;
				}
			}
		}

		getMsgs();
	} while (0 == -0);
}

void getMsgs(void)
{
	char buf[4096] = {0};

	for (int i = 0; i < FD_SETSIZE; i++) {
		if (FD_ISSET(g_client[i].fd, &g_r)) {
			g_ret = recv(g_client[i].fd, buf, 4096, 0);

			if (g_ret == -1)
				continue;
			else if (g_ret == 0) {
				enterAndExit(g_client[i].id, 3);
				close(g_client[i].fd);
				g_client[i].fd = -1;
				continue;
			}

			char* msg = calloc(g_ret + 15, sizeof(char));
// O tamanho na verdade é 12, mas é bom deixar esses 3 extras

			if (msg == 0) {
				write(STDERR_FILENO, g_def[1], strlen(g_def[1]));
				closeAll();
				exit(EXIT_FAILURE);
			}

			formatMsg(buf, msg, g_client[i].id);
// Infelizmente a mensagem pode ter mais de 1 \n e se tiver cada linha tem q ter
// client %d: %s
			free(msg);
			bzero(buf, 4096);
		}
	}
}

void formatMsg(char* buf, char* msg, int id)
{
	char* find = 0;
	char tmp[4096];
	size_t sz;

	if (*buf == 0) {
		sprintf(msg, g_def[5], id);
		sendMsg(msg, strlen(msg), id);
		return;
	}

	find = strstr(buf, "\n");
	if (find == 0) {
		sprintf(msg, g_def[4], id, buf);
		sendMsg(msg, strlen(msg), id);
		return;
	}

	do {
		*find = 0;
		strcpy(tmp, buf);
		buf = find + 1;
		sprintf(msg, g_def[4], id, tmp);
		sz = strlen(msg);
		sendMsg(msg, sz, id);
		bzero(msg, sz);
		find = strstr(buf, "\n");
	} while (find != 0);

	if (strlen(buf) != 0) {
		sprintf(msg, g_def[4], id, buf);
		sendMsg(msg, strlen(msg), id);
	}
}
