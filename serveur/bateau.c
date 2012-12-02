#include <stdio.h>
#include <stdlib.h>

#include "headers/bateau.h"

t_bateau* create_boat(t_case* cases, int nb_cases) {
	t_bateau* bateau = malloc(sizeof(t_bateau));
	bateau->taille = nb_cases;
	bateau->cases = cases;
	return bateau;
}