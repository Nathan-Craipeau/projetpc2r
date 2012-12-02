#include <stdio.h>
#include <stdlib.h>

#include "headers/game.h"

t_game* create_game(t_joueur** joueurs, t_socket* server) {
	t_game* game = malloc(sizeof(t_game));
	game->joueurs = joueurs;
	game->server = server;
	return game;
}