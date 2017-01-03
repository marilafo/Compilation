#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include "identificateur.h"

struct variable{
  char *name;
  enum type t;
  int level;
};

int length_hash = 100;
int current_length = 0;

int level=0;
  
int main(){
  char *tab[length_hash];
  ENTRY e, *ep;
  int i;

  hcreate(length_hash);

  struct variable v1 = {"toto", 0, level};

  tab[current_length]="toto";
  e.key = tab[current_length];
  e.data = &v1;
  ep = hsearch(e,ENTER);
  current_length++;
 
  if (ep == NULL) {
    fprintf(stderr, "entry failed\n");
    exit(EXIT_FAILURE);
  }

  struct variable *tmp;
  for (i = 0; i < current_length; i++) {
    /* print two entries from the table, and
       show that two are not in the table */
    e.key = tab[i];
    ep = hsearch(e, FIND);
    //printf("%9.9s -> %9.9s:%d\n", e.key,
    //	   ep ? ep->key : "NULL", ep ? (int)(ep->data) : 0);

    tmp = (struct variable *)ep->data;

    
    printf("%9.9s, %s, %d\n", ep? ep->key : "NULL", tmp->name, tmp->level);
  }
  hdestroy();
  exit(EXIT_SUCCESS);
}
