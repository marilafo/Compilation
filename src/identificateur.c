#include "identificateur.h"

struct expression* create_non_init_exp(char *name){
  struct expression *e = malloc(sizeof(struct expression));
  e->name = name;
  return e;
}

struct expression* create_exp(char *name, char *val, enum type t, int level){
  struct expression *e = malloc(sizeof(struct expression));
  e->name = name;
  init_exp(e,val,t,level);
  return e;
}

void init_exp(struct expression *e, char *val, enum type t, int level){
  e->t = t;
  e->val = val;
  e->param = NULL;
  e->size_param = -1;
  e->level = level;
}

void init_function(struct expression *e, char *val, enum type t, struct llist *l){
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

int nb_occ(struct llist *l, char *name){
  int total = 0;
  struct element *tmp;
  tmp = l->first;
  while(tmp != NULL){
    if(tmp->val->name == name)
      total++;
    tmp = tmp->next;
  }
  return total;
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

// /!\ attention ne marche que si fonction est bien de la forme "name_func"
/*char *name_func(char *fonction){
  char * copy;
  int l=strlen(fonction);
  int i=0;
  for(;i<l-5;i++)
    copy[i]=fonction[i];
  copy[l-5]='\0';
  return copy;    
}
*/


void free_expression(struct expression *e){
  if(e->param != NULL)
    free_llist(e->param);
  e->param=NULL;
  free(e);
}

void free_llist(struct llist *l){
  struct element *tmp;
  first=l->first;
  while(first->next != NULL){
    tmp = first->next;
    first->next=tmp->next;
    tmp->next=NULL;
    free_expression(tmp->val);
  }
  first->next=NULL;
  free(first);
}
