#include "sonde.h"
#include "point.h"

#define NB_BATEAUX 7
#define TAILLE 16
#define MAX_ACTIONS 17

typedef struct st_joueur {
	char* nom;
	char plateau[TAILLE][TAILLE];
	t_sonde* sonde;
	int nb_bateaux; // On conserve le nombre de "cases bateaux" pour connaître le nombre de coups restants.
	int coups_restants;
} t_joueur;

//Initialise un joueur vide.
t_joueur* create_empty_player();
// Setter pour une case du plateau d'un joueur.
void set_value(t_joueur* joueur, int x, int y, char value);
// Ajoute un bateau à un joueur.
int add_boat(t_joueur* joueur, t_point* points, int nb_points);
// Vérifie si un bateau est plaçable sur un terrain.
int valid_boat(t_point* points, int nb_points);

int valid_attack(t_joueur* target, int x, int y);

int attack(t_joueur* attacker, t_joueur* defender);

int move_sonde(t_joueur* joueur, char direction);

int valid_move(t_joueur* joueur, char direction);