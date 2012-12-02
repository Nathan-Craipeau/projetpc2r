#include <stdio.h>
#include <stdlib.h>

#include "headers/joueur.h"

#define true 1
#define false 0

t_joueur* create_empty_player() {
	t_joueur* joueur = malloc(sizeof(t_joueur));
	joueur->sonde = init_sonde();
	joueur->nb_bateaux = 0;
	joueur->coups_restants = MAX_ACTIONS - joueur->nb_bateaux;
	int i, j;
	for(i = 0; i<TAILLE; i++) {
		for(j = 0; j<TAILLE; j++) {
			joueur->plateau[i][j] = '.';
		}
	}
	return joueur;
}

void start_turn(t_joueur* joueur) {
	joueur->coups_restants = MAX_ACTIONS - joueur->nb_bateaux;
	joueur->sonde->a_tire = false;
}

void set_value(t_joueur* joueur, int x, int y, char value) {
	joueur->plateau[x][y] = value;
}

int add_boat(t_joueur* joueur, t_point* points, int nb_points) {
	if(valid_boat(points, nb_points)) {
		int i;
		for(i = 0; i< nb_points; i++) {
			int x = points[i].x;
			int y = points[i].y;
			set_value(joueur, x, y, 'B');
		}
		return true;
	}
	else return false;
}

int valid_boat(t_point* points, int nb_points) {
	int i;
	for(i = 1; i< nb_points; i++) {
		if((points[i].x != points[0].x && points[i].y != points[0].y) || (points[i].x == points[0].x && points[i].y == points[0].y)) return false;
	}
	return true;
}

int valid_attack(t_joueur* target, int x, int y) {
	if(target->plateau[x][y] != 'X' && target->plateau[x][y] != 'D') {
		return true;
	}
	else return false;
}

int attack(t_joueur* attacker, t_joueur* defender) {
	int x = attacker->sonde->x;
	int y = attacker->sonde->y;
	if(attacker->coups_restants >0 && valid_attack(defender, x, y)) {
		if(defender->plateau[x][y] == 'B') {
			defender->plateau[x][y] = 'D';
			defender->nb_bateaux--;
			attacker->sonde->a_tire = true;
		}
		else defender->plateau[x][y] = 'X';
		return true;
	}
	else return false;
}

int move_sonde(t_joueur* joueur, char direction) {
	if(joueur->coups_restants > 0 && valid_move(joueur, direction)) {
		if(direction == 'R') joueur->sonde->x++;
		if(direction == 'L') joueur->sonde->x--;
		if(direction == 'U') joueur->sonde->y--;
		if(direction == 'D') joueur->sonde->y++;
		return true;
	}
	else return false;
}

int valid_move(t_joueur* joueur, char direction) {
	if(direction == 'R' && joueur->sonde->x < TAILLE - 1) return true;
	if(direction == 'L' && joueur->sonde->x > 0) return true;
	if(direction == 'U' && joueur->sonde->y > 0) return true;
	if(direction == 'D' && joueur->sonde->y < TAILLE - 1) return true;
	return false;
}