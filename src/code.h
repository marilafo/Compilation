#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "identificateur.h"

//Struct pour la génération de code
struct generation{
  char *code;
  enum type t;
  char *name;
};

enum operation_code{
  ADD_OP = 0,
  SUB_OP = 1,
  MUL_OP = 2,
  DIV_OP = 3,
  REM_OP = 4,
  ASS_OP = 5,
  SHL_OP = 6,
  SHR_OP = 7,
  AND_OP = 8,
  OR_OP = 9,
  L_COMP = 10,
  G_COMP = 11,
  LE_COMP = 12,
  GE_COMP = 13,
  EQ_COMP = 14,
  NE_COMP = 15
};

//associe une nouvelle variable au prochain registre disponible, et renvoie la chainede charactères du registre codé en llvm
char *new_var();

//renvoie une fonction en llvm
char *new_func(char* function);

//renvoie un paramètre en llvm
char *new_param(char* name);

//associe un nouveau label à la prochaine valeur disponible, et renvoie ce numéro en llvm
char *new_label();

//renvoie le type d'une variable et son nom en llvm
char *get_type(char *name,enum type t);
