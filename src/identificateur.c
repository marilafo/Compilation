#include "identificateur.h"

struct expression* create_non_init_exp(char *name){
  struct expression *e = malloc(sizeof(struct expression));
  e->name = name;
  return e;
}

struct expression* create_exp(char *name, char *val, enum type t){
  struct expression *e = malloc(sizeof(struct expression));
  e->name = name;
  init_exp(e,0,t);
  return e;
}

void init_exp(struct expression *e, char *val, enum type t){
  e->t = t;
  e->val = val;
  e->param = NULL;
  e-> size_param = -1;
}

void init_function(struct expression *e, enum type t, char *val, struct llist *l){
  e->t = t;
  e->val = val;
  if(l == NULL)
    e->size_param = 0;
  else
    e->size_param = length_llist(l);
  e->param = l; 
}






struct llist *init_llist(){
  struct llist *l = malloc(sizeof(struct llist));
  l->first = NULL;
  l->size = 0;
  return l;
}

//ajout en tete de liste
void add_llist(struct llist *l, struct expression *e){
    struct element* elt = malloc(sizeof(struct element));
    elt->val = e;
    elt->next = l->first;
    l->first = elt;
    l->size += 1;
}


//renvoie la taille de la liste
int length_llist(struct llist *l){
  return l->size;
}


//recherche de la ième valeur de la liste
struct expression* look_for(struct llist *l, int indice){
  struct element *tmp;
  tmp = l->first;
  if(length_llist(l)<=indice)
    return NULL;
  while(indice != 0){
    tmp = tmp->next;
    indice --;
  }
  return tmp->val;
}


/*//parcours dans la liste
void parcours(llist liste)
{
  if(liste == NULL) {
    exit(EXIT_FAILURE);
  }
  
  element *temp = liste;
  while (temp->next != NULL) {
    ;//operation a faire
    temp = temp->next;
  }
  }*/


