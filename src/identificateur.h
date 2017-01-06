#ifndef CODAGE_TYPE_H
#define CODAGE_TYPE_H

#include <stdarg.h>
#include <stdlib.h>

enum type{
  INTEGER = 0,
  FLOATING = 1,
  VOID_T= 2,
  BOOL_T = 3,
  NOT_DEFINE = 4
};

union value{
  int n;
  double f;
};

struct expression{
  enum type t; 
  char *name; 
  char *val; 
  struct llist *param; //Liste des arguments de la fonction
  int size_param;// -1 si c'est pas une fonction 
  int level;
};

//liste chainée
struct llist{
  struct element *first;
  int size;
};

struct element{
  struct expression *val;
  struct element *next;
};

//déclare une expression en n'initialisant que le nom
struct expression* create_non_init_exp(char *name);

//déclare une expression et l'initialise avec les valeurs passées en paramètres
struct expression* create_exp(char *name, char *val, enum type t, int level);

//initialise un entier ou un flottant 
void init_exp(struct expression *e, char *val, enum type t, int level);

//initialise une fonction 
void init_function(struct expression *e,char *val, enum type t, struct llist *l);

//déclare et initialise une liste chainée à NULL
struct llist *init_llist();

//ajoute l'élément e en tête de la liste chainée l
void add_llist(struct llist *l, struct expression *e);

//renvoie la longueur d'une liste chainée
int length_llist(struct llist *list);

//renvoie l'expression situé à un indice donné dans une liste chainée
struct expression* look_for(struct llist *l, int indice);

//renvoie le nombre d'occurence du nom d'une expression dans une liste chainée
int nb_occ(struct llist *l, char *name);

//void parcours(llist);

//renvoie une chaine sans le '_func' à la fin
//char *name_func(char *fonction);

//parcours une chaine du type 'mot nom,mot nom,...,mot nom\o'
void parcours_arguments(char *arguments);

//libère une expression
void free_expression(struct expression *e);

//libère une liste chainée
void free_llist(struct llist *l);
#endif 
