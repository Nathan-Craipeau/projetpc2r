#include <stdio.h>
#include <stdlib.h>

#include "headers/joueur.h"

t_joueur* create_empty_player() {
	t_joueur* joueur = malloc(sizeof(t_joueur));
	joueur->plateau = create_empty_field();
	joueur->sonde = init_sonde();
	joueur->nb_bateaux = 0;
	return joueur;
}

void add_boat(t_joueur* joueur, t_bateau* bateau) {
	if(bateau != NULL) {
		joueur->bateaux[joueur->nb_bateaux] = *bateau;
		int i;
		for(i=0; i<bateau->taille; i++) {
			int cx = bateau->cases[i].x;
			int cy = bateau->cases[i].y;
			joueur->plateau->cases[cx][cy] = 'B';
		}
		joueur->nb_bateaux++;
	}
}