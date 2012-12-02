#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <fthread.h>

#include "headers/network.h"

#define true 1
#define false 0

#define SOCKET_ERROR -1
#define MAX_CLIENTS 4
#define PORT 2012
#define BUFFER_SIZE 1024

/**
 * Initialise la socket côté serveur afin de recevoir les connexions.
 * @return t_socket la socket initialisée côté serveur.
 */
t_socket init_connection() {
	printf("Début de l'initialisation du canal de communication pour HAL-9000... ");
	// Crée une nouvelle socket.
	t_socket sock = socket(AF_INET, SOCK_STREAM, 0);
	// Adresse destinée à la socket.
	t_sockaddr_in sin = {0};

	// Si la création de la socket a échoué, exit.
	if(sock == SOCKET_ERROR) {
		perror("Une erreur est survenue pendant la création de la socket ");
		exit(errno);
	}

	// Attache l'adresse destiné à la socket à l'adresse IP de la machine et au port 2012
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_port = htons(PORT);
	sin.sin_family = AF_INET;

	// Tente d'attacher l'adresse à la socket, exit sinon.
	if(bind(sock,(t_sockaddr *) &sin, sizeof sin) == SOCKET_ERROR) {
		perror("Une erreur est survenue pendant le bind() ");
		exit(errno);
	}

	// Essaye d'écouter sur la socket, exit sinon.
	if(listen(sock, MAX_CLIENTS) == SOCKET_ERROR) {
		perror("Une erreur est survenue pendant l'écoute sur la socket ");
		exit(errno);
	}

	printf("Le canal de communication est désormais effectif.\n");

	return sock;
}