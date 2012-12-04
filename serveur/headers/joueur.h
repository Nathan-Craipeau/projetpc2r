#include "sonde.h"
#include "network.h"
#include "point.h"

#define NB_BATEAUX 7
#define TAILLE 16
#define MAX_ACTIONS 17

typedef struct st_joueur {
	char* nom;
	char plateau[TAILLE][TAILLE];
	t_sonde* sonde;
	int nb_bateaux; // On conserve le nombre de "cases bateaux" pour connaître le nombre de coups restants à chaque début de tour.
	int coups_restants;
	t_socket sock;
} t_joueur;

//Initialise un joueur vide.
t_joueur* create_empty_player();
// Crée un joueur à partir d'une socket.
t_joueur* create_player(t_socket sock);
// Setter pour une case du plateau d'un joueur.
void set_value(t_joueur* joueur, int x, int y, char value);
// Ajoute un bateau à un joueur.
int add_boat(t_joueur* joueur, t_point* points, int nb_points);
// Vérifie si un bateau est plaçable sur un terrain.
int valid_boat(t_point* points, int nb_points);
// Vérifie qu'une attaque est valide (la case n'a pas encore été attaquée".
int valid_attack(t_joueur* target, int x, int y);
//attaque un joueur donné en paramètre d'après la position de la sonde de l'attaquant.
int attack(t_joueur* attacker, t_joueur* defender);
// Déplace la sonde d'une direction donnée en paramètre.
int move_sonde(t_joueur* joueur, char direction);
// Vérifie qu'un déplacement est valide.
int valid_move(t_joueur* joueur, char direction);
// Lance le tour d'un joueur.
void turn(t_joueur* joueur, t_joueur* joueurs, int nb_joueurs);
// affiche le terrain d'un joueur.
void afficher_terrain(t_joueur* joueur);
