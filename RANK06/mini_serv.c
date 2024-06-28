#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdint.h>
#include <netinet/ip.h>

typedef struct
{
	int			fd;
	uint32_t	id;
} t_client;

#define ARG_ERROR						"Wrong number of arguments\n"
#define FATAL_ERROR						"Fatal error\n"
#define NEW_CLIENT						"server: client %d just arrived\n"
#define MSG_CLIENT						"client %d: %s"
#define BYE_CLIENT						"server: client %d just left\n"
#define BUFFER_SIZE						10000
#define PRINT_ERROR(str)				write(STDERR_FILENO, str, sizeof(str))
#define WRITE_TO_THEM(str, fd, size)	send(fd, str, size, 0)

static void argError(int argc);
static void	startSocket(void);
static void bindSocket(uint16_t port);
static void setQueue(void);
static void waitForClients(void);

static int g_id = 0, sock_fd = -1;
static fd_set readers, writers;
static char	msg[BUFFER_SIZE] = {0};
static t_client client[FD_SETSIZE] = {0};


int main(int argc, char** argv)
{
	argError(argc);
	startSocket();
	bindSocket(atoi(argv[1]));
	setQueue();

	return EXIT_SUCCESS;
}


// STARTING --------------------------------------------------------------------
static void argError(int argc)
{
	if (argc < 2) {
		PRINT_ERROR(ARG_ERROR);
		exit(EXIT_FAILURE);
	}
}


static void startSocket(void)
{
	sock_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
	if (sock_fd == -1) {
		PRINT_ERROR(FATAL_ERROR);
		exit(EXIT_FAILURE);
	}
}


static void bindSocket(uint16_t port)
{
	struct sockaddr_in sock_addr = {0};

	port = (port << 8) | (port >> 8);
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port = port;
	sock_addr.sin_addr.s_addr = INADDR_LOOPBACK;

	if (bind(sock_fd, (struct sockaddr*)&sock_addr, sizeof(struct sockaddr_in))
		== -1
	) {
		PRINT_ERROR(FATAL_ERROR);
		close(sock_fd);
		exit(EXIT_FAILURE);
	}
}


static void setQueue(void)
{
	if (listen(sock_fd, FD_SETSIZE) == -1) {
		PRINT_ERROR(FATAL_ERROR);
		close(sock_fd);
		exit(EXIT_FAILURE);
	}
}
// -----------------------------------------------------------------------------


// MAIN LOOP -------------------------------------------------------------------
static void waitForClients(void)
{
	int		nfds = 0, ret = -1;

	do {
		FD_ZERO(&readers);
		FD_ZERO(&writers);
		nfds = addClientsToSet() + 1;
		ret = select(nfds, &readers, &writers, 0, 0);

		if (ret == -1)
			closeAndExit();
		else if (ret)
			listenAndRespond(nfds - 1);
	} while (0 == -0);
}


static void listenAndRespond(int limit)
{
	int i = 0;

	if (FD_ISSET(sock_fd, &readers)) {
		while (i < FD_SETSIZE && client[i].fd > 0)
			++i;
		if (i < FD_SETSIZE) {
			client[i].fd = accept(sock_fd, 0, 0);
			if (client[i].fd == -1)
				closeAndExit();
			client[i].id = id++;
			welcomeToTheServer(client[i], sizeof(NEW_CLIENT) + 4);
		}
	}
}
// -----------------------------------------------------------------------------


// PRINTERS --------------------------------------------------------------------
static void welcomeToTheServer(t_client c, size_t size)
{
	char* msg = calloc(size, sizeof(char));

	if (msg == 0)
		closeAndExit();
	sprintf(msg, NEW_CLIENT, c.id);
	for (int i = 0; i < FD_SETSIZE; i++) {
		if ()
	}
}
// -----------------------------------------------------------------------------
