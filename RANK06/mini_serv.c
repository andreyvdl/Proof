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


#define ARGS				"Wrong number of arguments\n"
#define FATAL				"Fatal error\n"
#define NEW					"server: client %d just arrived\n"
#define MSG					"client %d: %s"
#define BYE					"server: client %d just left\n"
#define BUF_SIZE			4096
#define PRINT_ERROR(str)	write(STDERR_FILENO, str, sizeof(str))


int g_id = 0, g_fd = -1, g_ret = -1, g_max = 2;
fd_set g_r;
t_client g_client[FD_SETSIZE] = {0};


void loop(void);
void getMsgs(void);


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

static void hello(int id)
{
	char msg[sizeof(NEW) + 2] = {0};

	sprintf(msg, NEW, id);
	sendMsg(msg, strlen(msg), id);
}

static void goodbye(int id)
{
	char msg[sizeof(BYE) + 2] = {0};

	sprintf(msg, BYE, id);
	sendMsg(msg, strlen(msg), id);
}


int main(int argc, char** argv)
{
	struct sockaddr_in sockaddr = {0};

	if (argc < 2) {
		PRINT_ERROR(ARGS);
		exit(EXIT_FAILURE);
	}

	g_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
	if (g_fd == -1) {
		PRINT_ERROR(FATAL);
		exit(EXIT_FAILURE);
	}

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(atoi(argv[1]));
	sockaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	if (bind(g_fd, (struct sockaddr*)&sockaddr, sizeof(struct sockaddr_in)) == -1) {
		PRINT_ERROR(FATAL);
		close(g_fd);
		exit(EXIT_FAILURE);
	}

	if (listen(g_fd, FD_SETSIZE) == -1) {
		PRINT_ERROR(FATAL);
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

		if (g_ret == -1) {
			PRINT_ERROR(FATAL);
			closeAll();
			exit(EXIT_FAILURE);
		}

		if (FD_ISSET(g_fd, &g_r)) {
			int new = accept(g_fd, 0, 0);

			if (new == -1) {
				PRINT_ERROR(FATAL);
				closeAll();
				exit(EXIT_FAILURE);
			}
			for (int i = 0; i < FD_SETSIZE; i++) {
				if (g_client[i].fd < 1) {
					g_client[i].fd = new;
					g_client[i].id = g_id++;
					hello(g_client[i].id);
					break;
				}
			}
		}

		getMsgs();
	} while (0 == -0);
}

void getMsgs(void)
{
	char buf[BUF_SIZE] = {0};

	for (int i = 0; i < FD_SETSIZE; i++) {
		if (FD_ISSET(g_client[i].fd, &g_r)) {
			g_ret = recv(g_client[i].fd, buf, BUF_SIZE, 0);

			if (g_ret == -1) {
				PRINT_ERROR(FATAL);
				closeAll();
				exit(EXIT_FAILURE);
			}
			else if (g_ret == 0) {
				goodbye(g_client[i].id);
				close(g_client[i].fd);
				g_client[i].fd = -1;
				continue;
			}
			size_t sz = strlen(buf);
			char* msg = calloc(sizeof(MSG) + sz, sizeof(char));

			if (msg == 0) {
				PRINT_ERROR(FATAL);
				closeAll();
				exit(EXIT_FAILURE);
			}
			sprintf(msg, MSG, g_client[i].id, buf);
			sendMsg(msg, strlen(msg), g_client[i].id);
			free(msg);
			bzero(buf, BUF_SIZE);
		}
	}
}
