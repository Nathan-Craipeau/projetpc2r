#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#include "headers/joueur.h"
#include "headers/commande.h"

#define true 1
#define false 0

#define MAX_PLAYERS 4

int main(void) {
	/*** Définition de variables. ***/
	t_socket server_socket;
	t_socket tmp_socket;
	t_joueur* joueurs[MAX_PLAYERS];
	int iplayer = 0;
	
	/*** Définition de schedulers, threads et events. ***/
	
	ft_event_t start_game = ft_event_create();
	ft_thread_t countdown = ft_thread_create(main_sched, countdown, NULL, NULL);
	
	/*** Instructions. ***/
	server_socket = init_connection();
	
	t_sockaddr_in csin = { 0 };
	size_t sinsize = sizeof csin;
	tmp_socket = accept(server_socket, (t_sockaddr*)&csin, (socklen_t*)&sinsize);
	
	joueurs[iplayer] = create_player(tmp_socket);
	iplayer++;
	
	return 0;
}
