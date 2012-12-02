#include <stdio.h>
#include <stdlib.h>

#include "headers/plateau.h"

t_plateau* create_empty_field() {
	int i, j;
	t_plateau* plateau = malloc(sizeof(t_plateau));
	for(i = 0; i<TAILLE; i++) {
		for(j = 0; j<TAILLE; j++) {
			plateau->cases[i][j] = '.';
		}
	}
	return plateau;
}