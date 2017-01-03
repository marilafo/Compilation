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
  char *val; //Valeur de retour si fonction ou entier ou float
  struct llist *param; //Liste des arguments de la fonction
  int size_param;// -1 si c'est pas une fonction 
  int level;
};


struct llist{
  struct element *first;
  int size;
};

struct element{
  struct expression *val;
  struct element *next;
};


struct expression* create_non_init_exp(char *name);
struct expression* create_exp(char *name, char *val, enum type t);
void init_exp(struct expression *e, char *val, enum type t);
void init_function(struct expression *e, enum type t, char *val, struct llist *l);

struct llist *init_llist();
void add_llist(struct llist *l, struct expression *e);
int length_llist(struct llist *list);
struct expression* look_for(struct llist *l, int indice);
//void parcours(llist);
#endif 
