#include "network.h"
#include "joueur.h"

typedef struct game {
	t_joueur** joueurs;
	t_socket* server;
} t_game;

t_game* create_game(t_joueur** joueurs, t_socket* server);