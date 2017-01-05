%{
#define _GNU_SOURCE
#include <stdio.h>
#include "identificateur.h"
#include "double_to_hex.c"
#include "code.c"
  
  
  //A enlever quand on aura les listes
  //int tab = 0;
  //int p = 0;

  char *code;
  
  extern int yylineno;
  int yylex ();
  int yyerror ();

    
  %}

%token <string> IDENTIFIER
%token <n> CONSTANTI
%token <f> CONSTANTF
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token SUB_ASSIGN MUL_ASSIGN ADD_ASSIGN DIV_ASSIGN
%token SHL_ASSIGN SHR_ASSIGN
%token REM_ASSIGN
%token REM SHL SHR
%token AND OR
%token TYPE_NAME
%token INT DOUBLE VOID
%token IF ELSE DO WHILE RETURN FOR
%type <exp> declarator function_declarator parameter_declaration
%type <gen> primary_expression postfix_expression unary_expression multiplicative_expression additive_expression expression conditional_expression logical_or_expression logical_and_expression shift_expression comparison_expression
%type <string> argument_expression_list assignment_operator selection_statement statement expression_statement compound_statement iteration_statement jump_statement statement_list compound_stat compound_dec declaration_list external_declaration type_name declaration function_definition program 
%type <list> declarator_list parameter_list
%start program
%union {
  char *string;
  int n;
  double f;

  struct llist *list;
  
  struct expression *exp;
  struct generation *gen;
}
%%
 //DONE
conditional_expression
: logical_or_expression{
  $$ = $1;
 }
;

//DONE
logical_or_expression
: logical_and_expression{
  $$ = $1;
 }
| logical_or_expression OR logical_and_expression{
  if(operation_expression($1, $3, OR_OP, 0) != NULL)
    $$ = operation_expression($1, $3, OR_OP, 0);
  else yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
;

//DONE
logical_and_expression
: comparison_expression{
  $$ = $1;
 }
| logical_and_expression AND comparison_expression{
  if(operation_expression($1, $3, AND_OP, 0) != NULL)
    $$ = operation_expression($1, $3, AND_OP, 0);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
;

//DONE
shift_expression
: additive_expression{
  $$ = $1;
 }
| shift_expression SHL additive_expression{
  if(operation_expression($1, $3, SHL_OP, 0) != NULL)
    $$ = operation_expression($1, $3, SHL_OP, 0);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
| shift_expression SHR additive_expression{
  if(operation_expression($1, $3, SHR_OP, 0) != NULL)
    $$ = operation_expression($1, $3, SHR_OP, 0);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
;

//DOING
primary_expression
: IDENTIFIER {
  //printf("%s\n",$1);
  tmp = action_identifier($1);
  $$ = malloc(sizeof(struct generation));
  $$->name = tmp->val;
  $$->t = tmp->t;
  $$->code = NULL;
  //asprintf(&($$->code), "%s", $$->name);
  //printf("%s", $$->name);      
 }
| CONSTANTI  {
  $$ = malloc(sizeof(struct generation));
  $$->name = new_var();
  $$->t = INTEGER;
  asprintf(&($$->code),"%s = add i32 0, %d\n", $$->name, $1);
  }
| CONSTANTF  {
  $$ = malloc(sizeof(struct generation));
  $$->name = new_var();
  $$->t = FLOATING;
  asprintf(&($$->code),"%s = fadd double %s, %s\n", $$->name, double_to_hex_str(0.0), double_to_hex_str($1));
  }
| '(' expression ')'{
  $$ = $2;
  }
| IDENTIFIER '(' ')' {
  //printf("%s\n",$1);
  //printf("Contenu hash table\n");
  //g_hash_table_foreach(hash_array[0], print_hash, NULL);
  $$ = malloc(sizeof(struct generation));
  tmp = map_with_name(new_func($1));
  //faire la vérif de type
  if(tmp == NULL){
    asprintf(&err, "Error: %s function not define", $1);
    yyerror(err);
  }    
  $$->name = tmp->val;
  $$->t = tmp->t;
  if(call_function($$->name, tmp->val, "", tmp->t) != NULL)
    asprintf(&($$->code), "%s",call_function($$->name, tmp->val, "", tmp->t));
  else 
    yyerror("Type non pris en compte");
  }
| IDENTIFIER '(' argument_expression_list ')'{
  //printf("%s\n", $1);
  //printf("Contenu hash table\n");
  //g_hash_table_foreach(hash_array[0], print_hash, NULL);
  $$ = malloc(sizeof(struct generation));
  //printf("mapping %s\n", new_func($1));
  tmp = map_with_name(new_func($1));
  //faire la vérif de type
  if(tmp == NULL){
    asprintf(&err, "Error: %s function not define", $1);
    yyerror(err);
  }
    
  $$->name = tmp->val;
  $$->t = tmp->t;
  if(call_function($$->name, tmp->val, $3, tmp->t)==NULL)
    asprintf(&($$->code), "%s", call_function($$->name, tmp->val, $3, tmp->t));
  else
    yyerror("Type non pris en compte");
  }
;

//DOING
postfix_expression
: primary_expression {
  $$ = $1;
 }
| IDENTIFIER INC_OP {
  //printf("%s\n", $1);
  if(op_1($1,ADD_OP) != NULL)
    $$ = op_1($1,ADD_OP);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
| IDENTIFIER DEC_OP{
  //printf("%s\n", $1);
  if(op_1($1,SUB_OP) != NULL)
    $$ = op_1($1,SUB_OP);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
;

//DOING
argument_expression_list
: expression{
  if(get_type($1->name, $1->t)!=NULL)
    asprintf(&$$,"%s",get_type($1->name, $1->t));
  else
    yyerror("Type non pris en compte");
 }
| argument_expression_list ',' expression{
  if(get_type($3->name, $3->t)!=NULL)
    asprintf(&$$,"%s, %s",$1, get_type($3->name, $3->t));
  else 
    yyerror("Type non pris en compte");
  }
;
//DOING
unary_expression
: postfix_expression{
  $$ = $1;
 }
| INC_OP IDENTIFIER {
  //printf("%s\n",$2);
  if(op_1($2, ADD_OP) != NULL)
    $$ = op_1($2, ADD_OP);
  else 
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
| DEC_OP IDENTIFIER{
  //printf("%s\n",$2);
  if(op_1($2, SUB_OP) != NULL)
    $$ = op_1($2, SUB_OP);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
| unary_operator unary_expression{
  $$ = malloc(sizeof(struct generation));
  $$->name = new_var();
  $$->t = $2->t;
  switch($$->t){
  case INTEGER :
    asprintf(&($$->code),"%s%s = sub i32 0, %s\n",$2->code, $$->name, $2->name);
    break;
  case FLOATING:
    asprintf(&($$->code),"%s%s = fsub double %s, %s\n",$2->code, $$->name, double_to_hex_str(0.0), $2->name);
    break;
  default:
    yyerror("Impossible de rendre négatif, type incompatible");
  }
 }
;

//DONE
unary_operator
: '-'
;

//DOING
multiplicative_expression
: unary_expression{
  $$ = $1;
 }
| multiplicative_expression '*' unary_expression {
  if(operation_expression($1, $3, MUL_OP, 0) != NULL)
    $$ = operation_expression($1, $3, MUL_OP, 0);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles test");
  }
| multiplicative_expression '/' unary_expression{
  if(operation_expression($1, $3, DIV_OP, 0) != NULL)
    $$ = operation_expression($1, $3, DIV_OP, 0);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
  }
| multiplicative_expression REM unary_expression{
  if(operation_expression($1, $3, REM_OP, 0) != NULL)
    $$ = operation_expression($1, $3, REM_OP, 0);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
;

//DOING
additive_expression
: multiplicative_expression{
  $$ = $1;
 }
| additive_expression '+' multiplicative_expression{
  if(operation_expression($1, $3, ADD_OP, 0) != NULL)
    $$ = operation_expression($1, $3, ADD_OP, 0);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
  }
| additive_expression '-' multiplicative_expression{
  if(operation_expression($1, $3, SUB_OP, 0) != NULL)
    $$ = operation_expression($1, $3, SUB_OP, 0);
  else 
    yyerror("Operation non prise en compte, Type et operation non compatibles");
  }
;

//DOING
comparison_expression
: shift_expression{
  $$ = $1;
 }
| comparison_expression '<' shift_expression{
  if(operation_expression($1, $3, L_COMP, 1) != NULL)
    $$ = operation_expression($1, $3, L_COMP, 1);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
  }
| comparison_expression '>' shift_expression{
  if(operation_expression($1, $3, G_COMP, 1) != NULL)
    $$ = operation_expression($1, $3, G_COMP, 1);
  else
  yyerror("Operation non prise en compte, Type et operation non compatibles");
  }
| comparison_expression LE_OP shift_expression{
  if(operation_expression($1, $3, LE_COMP, 1) != NULL)
    $$ = operation_expression($1, $3, LE_COMP, 1);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
 }
| comparison_expression GE_OP shift_expression{
  if(operation_expression($1, $3, GE_COMP, 1) != NULL)
    $$ = operation_expression($1, $3, GE_COMP, 1);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
 }
| comparison_expression EQ_OP shift_expression{
  if(operation_expression($1, $3, EQ_COMP, 1) != NULL)
    $$ = operation_expression($1, $3, EQ_COMP, 1);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
 }
| comparison_expression NE_OP shift_expression{
  if(operation_expression($1, $3, NE_COMP, 1) != NULL)
    $$ = operation_expression($1, $3, NE_COMP, 1);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
 }
;

//DOING
expression
: unary_expression assignment_operator conditional_expression{
  if(operation_expression($1, $3, string_to_op_code($2), 0) != NULL){
    $$ = operation_expression($1, $3, string_to_op_code($2), 0);
    //asprintf(&($$->code), "%s%s",$$->code,store_value($3->name, $1->name, $$->t)); 
  }
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
 }
| conditional_expression{
  $$ = $1;
  }
;

//DONE
assignment_operator
: '='{
  $$ = "ass";
 }
| MUL_ASSIGN{
  $$ = "mul";
  }
| DIV_ASSIGN{
  $$ = "div";
  }
| REM_ASSIGN{
  $$ = "rem";
  }
| SHL_ASSIGN{
  $$ = "shl";
  }
| SHR_ASSIGN{
  $$ = "shr";
  }
| ADD_ASSIGN{
  $$ = "add";
  }
| SUB_ASSIGN{
  $$ = "sub";
  }
;

//DOING
declaration
: type_name declarator_list ';'{
  int length_l = length_llist($2);
  
  int i = 0;
  struct expression *tmp;
  for(; i<length_l; i++){
    tmp = look_for($2, i); 
    tmp->t = string_to_type($1);
    tmp->level = level;
    if(g_hash_table_contains(hash_array[level], tmp->name))
      yyerror(&err, "Redéclaration de la variable %s", tmp->name);
    else
      g_hash_table_insert(hash_array[level], tmp->name, tmp);
  }
  
 }
;

//DOING
//METTRE LES LISTES 
declarator_list
//: declarator_init
: declarator{
  $$ = init_llist();
  add_llist($$, $1);
 }
//| declarator_list ',' declarator_init
| declarator_list ',' declarator{
  $$ = $1;
  add_llist($$, $3);
  }
;

//DONE
type_name
: VOID{
  $$ = "void";
  last_type = VOID_T;
 }
| INT{
  $$ = "int";
  last_type = INTEGER;
  }
| DOUBLE{
  $$ = "double";
  last_type = FLOATING;
  }
;

//DOING
//GESTION TABLE DE HASH
//GENERATION CODE
function_declarator
: declarator '(' parameter_list ')'{
  $$ = $1;
  init_function($$, new_func($$->name), last_type, $3);
  if(!g_hash_table_contains(hash_array[level], new_func($1->name)))
    g_hash_table_insert(hash_array[level], new_func($1->name), $$);
  //Sinon vérification de param
  int i = 0;
  for(; i < length_llist($3); ++i){
    tmp = look_for($3, i);
    if(tmp->t != VOID_T){
      if(nb_occ($3, tmp->name) != 1){
	asprintf(&err, "Error: param %s already initialize\n", tmp->name);
	yyerror(err);
      }
      if(!g_hash_table_contains(hash_array[level],new_param(tmp->name)))
	g_hash_table_insert(hash_array[level], new_param(tmp->name),tmp);
    }
    else{
      asprintf(&err,"Error:impossible to have void parameter :%s", tmp->name);
      yyerror(err);
    }
  }
 }
| declarator '(' ')'{
  if(!g_hash_table_contains(hash_array[level], new_func($1->name)))
    g_hash_table_insert(hash_array[level], new_func($1->name), $$);
  //Sinon vérification de param
  $$ = $1;
  init_function($$,new_func($$->name), last_type, NULL);
  }
;

//DOING
//GESTION TABLE HASH
//GENERATION CODE
declarator
: IDENTIFIER {
  //printf("%s\n",$1);
  $$ = create_non_init_exp($1);
 }
| '(' declarator ')'{
  $$ = $2;
  }
| declarator '(' parameter_list ')'{
    $$ = $1;
    
    init_function($$, new_func($$->name), last_type, $3);
    if(!g_hash_table_contains(hash_array[level], new_func($1->name)))
      g_hash_table_insert(hash_array[level], new_func($1->name), $$);
    //Sinon vérification de param
    int i = 0;
    for(; i < length_llist($3); ++i){
      tmp = look_for($3, i);
      if(tmp->t != VOID_T){
	if(nb_occ($3, tmp->name) != 1)
	  asprintf(&err, "Error: param %s already initialize\n", tmp->name);
	yyerror(err);
	if(!g_hash_table_contains(hash_array[level],new_param(tmp->name)))
	  g_hash_table_insert(hash_array[level], new_param(tmp->name),tmp);
      }
      else
	asprintf(&err,"Error:impossible to have void parameter :%s", tmp->name);
      yyerror(err);
    }
  }
| declarator '(' ')'{
  $$ = $1;
  init_function($$, new_func($$->name), last_type, NULL);
  if(!g_hash_table_contains(hash_array[level], new_func($1->name)))
    g_hash_table_insert(hash_array[level], new_func($1->name), $$);
  //Sinon vérification de param
  }
;
  
/*declarator_init
  : declarator{
  $$ = $1;
  }
  | IDENTIFIER '=' expression{
  switch($3->t){
  case INTEGER:
  $$ = create_int($3
  case FLOATING:
  default:
  printf("Error\n");
  }
  ;*/

//DOING
parameter_list
: parameter_declaration{
  $$ = init_llist();
  add_llist($$, $1);
 }
| parameter_list ',' parameter_declaration{
  $$ = $1;
  add_llist($$, $3);
  }
;

//DOING
parameter_declaration
: type_name declarator{
  $$ = $2;
  init_exp($$, new_param($$->name), string_to_type($1), level);
  //printf("Dec : %s, %d, %s\n", $2->val, $2->t, $2->name);
 }
;

//DOING
statement
: compound_statement{
  $$ = $1;
 }
| expression_statement{
  $$ = $1;
  }
| iteration_statement{
  $$ = $1;
  }
| jump_statement{
  $$ = $1;
  }
| selection_statement{
  $$ = $1;
  }
;

//DOING
LB : '{'{
  level++;
  if(level >= max_hash){
    int i = max_hash;
    max_hash = max_hash * 2;
    hash_array = realloc(hash_array, max_hash);
    for(; i < max_hash ; ++i)
      hash_array[i] = NULL;
  }
  if(hash_array[level] != NULL)
    g_hash_table_remove_all(hash_array[level]);
  else
    hash_array[level] = g_hash_table_new(g_str_hash, g_str_equal);
 }
;

//DOING
RB : '}'{
  g_hash_table_foreach(hash_array[level], value, NULL);
  
  level--;
 }
;

//DOING
compound_statement
: LB RB{
  $$ = NULL;
  
 }
| LB compound_stat RB{
  $$ = $2;
 }
| LB compound_dec RB{
  $$ = $2;
 }
;

//DOING
compound_stat
: statement_list {
  $$ = $1;
 }
| statement_list compound_dec{
  asprintf(&$$,"%s%s", $1, $2);
 }
;

//DOING
compound_dec
: declaration_list{
  $$ = $1;
 }
| declaration_list compound_stat{
  asprintf(&$$, "%s%s", $1, $2);
 }
;

//DOING
declaration_list
: declaration{
  $$ = $1;
 }
| declaration_list declaration{
  asprintf(&$$,"%s%s", $1, $2);
 }
;

//DOING
statement_list
: statement{
  $$ = $1;
 }
| statement_list statement{
  asprintf(&$$,"%s%s", $1, $2);
 }
;

//DOING
expression_statement
: ';'
{
  $$ = NULL;
}
| expression ';'{
  $$ = $1->code;
  }
;

//DOING
selection_statement
: IF '(' expression ')' statement{
  $$ = if_expression($3->name, $3->code, $5, NULL);
 }
| IF '(' expression ')' statement ELSE statement{
  $$ = if_expression($3->name, $3->code, $5, $7);
  }
| FOR '(' expression ';' expression ';' expression ')' statement{
  $$ = for_expression($3->code, $7->code, $5, $9);
  }
| FOR '(' expression ';' expression ';'            ')' statement{
  $$ = for_expression($3->code, NULL, $5, $8);
  }
| FOR '(' expression ';'            ';' expression ')' statement{
  $$ = for_expression($3->code, $6->code, NULL, $8);
  }
| FOR '(' expression ';'            ';'            ')' statement{
  $$ = for_expression($3->code, NULL, NULL, $7);
  }
| FOR '('            ';' expression ';' expression ')' statement{
  $$ = for_expression(NULL, $6->code, $4, $8);
  }
| FOR '('            ';' expression ';'            ')' statement{
  $$ = for_expression(NULL, NULL, $4, $7);
  }
| FOR '('            ';'            ';' expression ')' statement{
  $$ = for_expression(NULL, $5->code, NULL, $7);
  }
| FOR '('            ';'            ';'            ')' statement{
  $$ = for_expression(NULL, NULL, NULL, $6);
  }
;

//DOING
iteration_statement
: WHILE '(' expression ')' statement{
  $$ = for_expression(NULL, $3->code, NULL, $5);
 }
| DO statement WHILE '(' expression ')' ';'{
  asprintf(&$$,"%s%s", $2,for_expression(NULL, $5->code, NULL, $2));
 }
;

//DOING
jump_statement
: RETURN ';'{
  if(return_expression(VOID_T, NULL) != NULL)
    $$ = return_expression(VOID_T, NULL);
  else
    yyerror("Type non pris en compte");
 }
| RETURN expression ';'{
  if(return_expression($2->t, $2->name) != NULL)
    $$ = return_expression($2->t, $2->name);
  else
    yyerror("Type non pris en compte");
 }
;

//DOING
program
: external_declaration{
  $$ = $1;
  code = $$;
 }
| program external_declaration{
  asprintf(&$$, "%s%s", $1, $2);
  code = $$;
 }
;

//DOING
external_declaration
: function_definition{
  $$ = $1;
 }
| declaration{
  $$ = $1;
  }
;

//TODO
function_definition
: type_name function_declarator compound_statement{
  $2->t = string_to_type($1);
  $2->level = level;
  switch($2->t){
  case INTEGER:
    if(parameter_to_string($2) != NULL)
      asprintf(&$$,"define i32 %s(%s){\n", new_func($2->name), parameter_to_string($2));
    else
      yyerror("Type non pris en compte");
    break;
  case FLOATING:
    if(parameter_to_string($2) != NULL)
      asprintf(&$$,"define double %s(%s){\n", new_func($2->name), parameter_to_string($2));
    else
      yyerror("Type non pris en compte");
    break;
  case VOID_T:
    if(parameter_to_string($2) != NULL)
      asprintf(&$$,"define void %s(%s){\n", new_func($2->name), parameter_to_string($2));
    else
      yyerror("Type non pris en compte");
    break;
  default:
    yyerror("Type booléen ou non défini ne peuvent pas etre le type de retour d'une fonction");
    //printf("Error\n");
  }

  
  asprintf(&$$,"%s%s",$$, $3);  
  asprintf(&$$,"%s}\n",$$);


  
 }
;

%%
#include <stdio.h>
#include <string.h>

extern char yytext[];
extern int column;
extern int yylineno;
extern FILE *yyin;

char *file_name = NULL;

int yyerror (char *s) {
  fflush (stdout);
  fprintf (stderr, "%s:%d:%d: %s\n", file_name, yylineno, column, s);
  return 0;
}

int main (int argc, char *argv[]) {

  hash_array = calloc(max_hash, sizeof(GHashTable *));
  hash_array[level] = g_hash_table_new(g_str_hash, g_str_equal);
  int i = 1;
  for (; i < max_hash ; ++i)
    hash_array[i] = NULL;
  FILE *input = NULL;
  if (argc==2) {
    input = fopen (argv[1], "r");
    file_name = strdup (argv[1]);
    if (input) {
      yyin = input;
    }
    else {
      fprintf (stderr, "%s: Could not open %s\n", *argv, argv[1]);
      return 1;
    }
  }
  else {
    fprintf (stderr, "%s: error: no input file\n", *argv);
    return 1;
  }
  yyparse ();
  printf("%s\n", code);
  free (file_name);

  i = 0;
  for(; i < max_hash ; i++)
    if(hash_array[i] != NULL){
      g_hash_table_destroy(hash_array[i]);
    }
  free(hash_array);

  
  return 0;
}
