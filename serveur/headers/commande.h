typedef struct argument t_argument;

// Un item de la liste d'arguments.
struct argument {
	char* contenu;
	t_argument* suivant;
};

// Liste d'arguments (chainée).
typedef struct arguments {
	t_argument* first;
	t_argument* last;
	int length;
} t_arguments;

// Commande alliant une fonction et des arguments.
typedef struct commande {
	char* fonction;
	t_arguments* args;
} t_commande;

// Crée une liste vide.
t_arguments* empty_list();
// Construit un item d'une liste à partir d'une chaine.
t_argument* build_arg(char* chaine);
// construit une liste à partir d'une chaine.
t_arguments* build_from(char* chaine);
// Ajoute une chaine à une liste.
void add_string(char* chaine, t_arguments* list);
// Ajoute un item à une liste.
void add_item(t_argument* item, t_arguments* list);
// renvoie l'item à la position spécifiée.
char* item_at(int indice, t_arguments* list);
// Crée une commande vide.
t_commande* create_empty_commande();
// Interprête une commande passée sous forme de chaine de caractères.
t_commande* interpret_string(char* line);
