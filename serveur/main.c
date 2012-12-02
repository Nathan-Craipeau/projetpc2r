#include <stdio.h>
#include <stdlib.h>

#include "headers/joueur.h"
#include "headers/network.h"

void afficher_terrain(t_joueur* joueur) {
	int i, j;
	for(i=0; i<TAILLE; i++) {
		for(j=0; j<TAILLE; j++) {
			printf("%c", joueur->plateau->cases[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	t_socket sock = init_connection();

	t_joueur* joueur = create_empty_player();

	t_case c[4];
	c[0].x = 5;
	c[0].y = 2;
	c[1].x = 5;
	c[1].y = 3;
	c[2].x = 5;
	c[2].y = 4;
	c[3].x = 5;
	c[3].y = 5;

	t_bateau* bateau = create_boat(c, 4);

	add_boat(joueur, bateau);

	afficher_terrain(joueur);

	return 0;
}