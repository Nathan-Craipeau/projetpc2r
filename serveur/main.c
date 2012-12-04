#include <stdio.h>
#include <stdlib.h>

#include "headers/joueur.h"
#include "headers/network.h"
#include "headers/commande.h"

void afficher_terrain(t_joueur* joueur) {
	int i, j;
	for(i=0; i<TAILLE; i++) {
		for(j=0; j<TAILLE; j++) {
			printf("%c", joueur->plateau[j][i]);
		}
		printf("\n");
	}
}

int main(void) {
	
	t_commande* com = interpret("COMMANDE/ARG1/ARG2");
	
	printf("%s\n", com->fonction);
	printf("%s\n", com->args->first->contenu);
	printf("%s\n", com->args->last->contenu);
	
	//t_socket sock = init_connection();

	t_joueur* joueur = create_empty_player();

	t_point points[3];
	points[0].x = 1;
	points[0].y = 1;
	points[1].x = 1;
	points[1].y = 1;

	add_boat(joueur, points, 2);

	move_sonde(joueur, 'U');
	move_sonde(joueur, 'D');
	move_sonde(joueur, 'D');
	move_sonde(joueur, 'R');

	attack(joueur, joueur);

	move_sonde(joueur, 'R');

	attack(joueur, joueur);

	move_sonde(joueur, 'U');
	move_sonde(joueur, 'U');
	move_sonde(joueur, 'U');
	
	attack(joueur, joueur);

	//afficher_terrain(joueur);

	return 0;
}
