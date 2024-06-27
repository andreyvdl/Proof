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

#define ARG_ERROR						"Wrong number of arguments\n"
#define FATAL_ERROR						"Fatal error\n"
#define NEW_CLIENT						"server: client %d just arrived\n"
#define MSG_CLIENT						"client %d: %s\n"
#define BYE_CLIENT						"server: client %d just left\n"
#define MAX_QUEUE						100
#define ONE_MEGABYTE					1048576
#define PRINT_ERROR(str)				write(STDERR_FILENO, str, sizeof(str))
#define WRITE_TO_THEM(str, fd, size)	send(fd, str, size, 0)

static void argError(int argc);
static int	startSocket(void);
static void bindSocket(int sock_fd, uint16_t port);
static void setQueue(int sock_fd);

static uint32_t getId(void)
{
	static uint32_t id = 0;

	return &id;
}


int main(int argc, char** argv)
{
	int sock_fd = -1;

	argError(argc);
	sock_fd = startSocket();
	bindSocket(sock_fd, atoi(argv[1]));
	setQueue(sock_fd);

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


static int startSocket(void)
{
	int fd = -1;

	fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
	if (fd == -1) {
		PRINT_ERROR(FATAL_ERROR);
		exit(EXIT_FAILURE);
	}
	return fd;
}


static void bindSocket(int sock_fd, uint16_t port)
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


static void setQueue(int sock_fd)
{
	if (listen(sock_fd, MAX_QUEUE) == -1) {
		PRINT_ERROR(FATAL_ERROR);
		close(sock_fd);
		exit(EXIT_FAILURE);
	}
}
// -----------------------------------------------------------------------------


// MAIN LOOP -------------------------------------------------------------------
static void waitForClients(int sock_fd)
{

}
// -----------------------------------------------------------------------------
