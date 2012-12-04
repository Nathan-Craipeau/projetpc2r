#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/commande.h"

t_arguments* empty_list() {
	t_arguments* tmp = malloc(sizeof(t_arguments));
	tmp->length = 0;
	return tmp;
}

t_argument* build_arg(char* chaine) {
	t_argument* arg = malloc(sizeof(t_argument));
	arg->contenu = chaine;
	arg->suivant = NULL;
	return arg;
}

t_arguments* build_from(char* chaine) {
	t_argument* first = build_arg(chaine);
	t_arguments* tmp = empty_list();
	tmp->first = first;
	tmp->last = first;
	tmp->length++;
	return tmp;
}

void add_string(char* chaine, t_arguments* list) {
	if(list->length <= 0) {
		list = build_from(chaine);
	}
	else {
		t_argument* item = build_arg(chaine);
		list->last->suivant = item;
		list->last = item;
		list->length++;
	}
}

void add_item(t_argument* item, t_arguments* list) {
	if(list->length <= 0) {
		list->first = item;
		list->last = item;
	}
	else {
		list->last->suivant = item;
		list->last = item;
	}
	list->length++;
}

char* item_at(int indice, t_arguments* list) {
	if(list->length <= 0 || indice >= list->length) return NULL;
	else {
		int i;
		t_argument* tmp = list->first;
		for(i = 0; i < indice; i++) {
			tmp = tmp->suivant;
		}
		return tmp->contenu;
	}
}

t_commande* create_empty_commande() {
	t_commande* com = malloc(sizeof(t_commande));
	com->args = empty_list();
	return com;
}

t_commande* interpret_string(char* line) {
	char* str = strdup(line);
	t_commande* com = create_empty_commande();
	
	char * tmp;
	tmp = strtok(str, "/");
	com->fonction = tmp;
	tmp = strtok (NULL,"/");
	while (tmp != NULL) {
		t_argument* item = build_arg(strdup(tmp));
		add_item(item, com->args);
		tmp = strtok (NULL, "/");
	}
	return com;
}
