#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#include <pthread.h>
#include <fthread.h>

#include "headers/game.h"
#include "headers/commande.h"

#define true 1
#define false 0

#define MAX_PLAYERS 4

void p(void* arg) {
	t_game* game = (t_game*) arg;
	t_socket* socket = game->server;
	printf("quelque chose\n");
	printf("%d\n", *socket);
	ft_thread_cooperate();
}

int main(void) {
	t_joueur* joueurs[MAX_PLAYERS];
	t_socket* serversocket = malloc(sizeof(t_socket));
	*serversocket = init_connection();
	printf("%d\n", *serversocket);
	t_game* game = create_game(joueurs, serversocket);

	ft_scheduler_t sched = ft_scheduler_create();
	ft_thread_create(sched, p, NULL, game);
	ft_scheduler_start(sched);
	ft_exit();
	return 0;
}
