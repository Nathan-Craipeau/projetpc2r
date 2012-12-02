#include "case.h"

typedef struct st_bateau {
	int taille;
	t_case* cases;
} t_bateau;

t_bateau* create_boat(t_case* cases, int nb_cases);