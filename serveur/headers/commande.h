typedef struct argument t_argument;

struct argument {
	char* contenu;
	t_argument* suivant;
};

typedef struct arguments {
	t_argument* first;
	t_argument* last;
	int length;
} t_arguments;

typedef struct commande {
	char* fonction;
	t_arguments* args;
} t_commande;

t_arguments* empty_list();
t_argument* build_arg(char* chaine);
t_arguments* build_from(char* chaine);
void add_string(char* chaine, t_arguments* list);
void add_item(t_argument* item, t_arguments* list);
char* item_at(int indice, t_arguments* list);
t_commande* create_empty_commande();
t_commande* interpret(char* line);
