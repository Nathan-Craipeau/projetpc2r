#define TAILLE 16

typedef struct st_plateau {
	char cases[TAILLE][TAILLE];
} t_plateau;

t_plateau* create_empty_field();