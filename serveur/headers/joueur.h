#include "plateau.h"
#include "sonde.h"
#include "bateau.h"

#define NB_BATEAUX 7

typedef struct st_joueur {
	char* nom;
	t_plateau* plateau;
	t_sonde* sonde;
	t_bateau bateaux[NB_BATEAUX];
	int nb_bateaux;
} t_joueur;

t_joueur* create_empty_player();
void add_boat(t_joueur* joueur, t_bateau* bateau);