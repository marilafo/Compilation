#define CODE_H
#ifndef CODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "identificateur.h"


//Permet de remplir yyerror!
char *err;
  
//Niveau pour les déclarations de variables
int level;

//Compteurs variables temporaire
int num_var = 0;

//Compteurs de label
int num_label = 0;

enum type last_type;

int max_hash = 10;

GHashTable ** hash_array;


//Struct pour la génération de code
struct generation{
  char *code;
  enum type t;
  char *name;
};

struct exp_code{
  struct expression *g;
  char *code;
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

//renvoie en llvm le nome d'une fonction
char *new_func(char* function);

//renvoie en llvm le nom d'un paramètre
char *new_param(char* name);

//associe un nouveau label à la prochaine valeur disponible, et renvoie ce numéro, en llvm
char *new_label();

//renvoie le type d'une variable et son nom en llvm
char *get_type(char *name,enum type t);

//fonction permettant d'afficher tous les éléments de la table de hashage en la passant en paramètre de la fonction foreach de la table de hashage
void print_hash(gpointer key, gpointer value, gpointer user_data);

//renvoie la dernière valeur de l'expression de nom name et de type t en redescendant les niveaux 
struct expression *map_symbol(char *name, enum type t);

//fais la même chose que map_symbol mais ne compare pas les types
struct expression *map_with_name(char *name);

//renvoie tous les éléments de la table de hashage en la passant en paramètre de la fonction foreach de la table de hashage
void value(gpointer key, gpointer value, gpointer user_data);

//renvoie la valeur de l'expression de nom name en regardant dans le level actuel si elle y est, sinon la créée au level -1
struct expression * action_identifier(char *name);

//renvoie en llvm l'appel de la fonction fun avec comme arguments arg suivant le type t de retour de la fonction
char *call_function(char *var, char *fun, char *arg ,enum type t);

//renvoie en llvm le chargement de la variable var de type t dans le registre res
char *load_value(char *res, char* var, enum type t);

//renvoie en llvm l'enregistrement de la variable var de type t dans le pointeur ptr
char *store_value(char *var, char* ptr, enum type t);

//renvoie en llvm l'opération op avec pour argument arg1 et arg2 (entiers) dont le résultat est envoyé dans le registre res
char *made_op_int(char *res, char *arg1, char *arg2, enum operation_code op);

//renvoie en llvm l'opération op avec pour argument arg1 et arg2 (flottants) dont le résultat est envoyé dans le registre res
char *made_op_double(char *res, char *arg1, char *arg2, enum operation_code op);

//renvoie en llvm la comparaison comp avec pour argument arg1 et arg2 (entiers) dont le résultat est envoyé dans le registre res
char *made_comparison_int(char *res, char *arg1, char *arg2, enum operation_code comp);

//renvoie en llvm la comparaison comp avec pour argument arg1 et arg2 (flottants) dont le résultat est envoyé dans le registre res
char *made_comparison_double(char *res, char *arg1, char *arg2, enum operation_code comp);

//renvoie en llvm l'opération op effectuée à la variable et 1 (incrémentation, décrémentation) dont le résultat est envoyé dans le registre de la variable de nom name 
struct generation *op_1(char *name, enum operation_code op );

//concatène le code de a et le code de b dans ret
void insert_previous_exp(struct generation *ret, struct generation *a, struct generation *b);

//renvoie en llvm le code d'une opération quelle qu'elle soit
struct generation *operation_expression(struct generation *a, struct generation *b, enum operation_code c, int made_code);

//renvoie en llvm le code d'un if avec comme condition cond, comme variable var, t est le code à faire si la condition est vraie, et f est le code à faire si la condition est fausse et qu'il y a un else   
char * if_expression(char *var, char *cond, char *t, char *f);

//renvoie en llvm le code d'un for avec comme condition cond, comme variable var, init est l'initialisation avant la boucle for, et b est le code a effectuer dans la boucle 
char * for_expression(char *init, char *inc, struct generation *cond, char * b);

//renvoie en llvm le code d'un return avec comme variable à retourner var et son type est t
char *return_expression(enum type t, char* var);

//converti une chaine de charactère qui décrit une opération en l'enum operation_code associé
enum operation_code string_to_op_code(char *s);

//converti une chaine de charactère qui décrit un type en l'enum type associé
enum type string_to_type(char *s);

//renvoie en llvm le type et la valeur des arguments de la fonction e
char *parameter_to_string(struct expression *e);

//supprime les paramètres de la fonction e de la table de hashage
void remove_param_hash_table(struct expression *e);

//déclare les pointeurs qui contiendront les valeurs des paramètres de la fonction fun
char * alloca_param(struct expression *fun);

//renvoie un double nom d'un paramètre de type double 
struct expression * double_param(char *name);

//déclare les fonctions de dessin nécessaire pour créer une fractale
void insert_declaration(GHashTable * hash);

#endif
