%{
#define _GNU_SOURCE
#include <stdio.h>
#include "identificateur.h"
#include "double_to_hex.c"
#include "code.c"
  
  

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
 
conditional_expression
: logical_or_expression{
  $$ = $1;
 }
;

 
logical_or_expression
: logical_and_expression{
  $$ = $1;
 }
| logical_or_expression OR logical_and_expression{
  $$ = operation_expression($1, $3, OR_OP, 0);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles");
    return -1;
  }
 }
;

 
logical_and_expression
: comparison_expression{
  $$ = $1;
 }
| logical_and_expression AND comparison_expression{
  $$ = operation_expression($1, $3, AND_OP, 0);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles");
    return -1;
  }
 }

;

 
shift_expression
: additive_expression{
  $$ = $1;
 }
| shift_expression SHL additive_expression{
  $$ = operation_expression($1, $3, SHL_OP, 0);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles");
    return -1; 
  }
 }
| shift_expression SHR additive_expression{
  $$ = operation_expression($1, $3, SHR_OP, 0);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles");
    return -1;
  } 
 }
;

 
primary_expression
: IDENTIFIER {
  struct exp_code d = action_identifier($1);
  struct expression *tmp = d.g;

  $$ = malloc(sizeof(struct generation));
  $$->name = tmp->val;
  $$->t = tmp->t;
  $$->code = d.code;
 }
| CONSTANTI  {
  $$ = malloc(sizeof(struct generation));
  char *var_tmp = new_var();
  $$->name = new_var();
  $$->t = INTEGER;
  asprintf(&($$->code),"%s = add i32 0, %d\n", var_tmp, $1);
  asprintf(&($$->code),"%s%s = alloca i32\n", $$->code, $$->name);
  asprintf(&($$->code),"%s%s", $$->code, store_value(var_tmp, $$->name, INTEGER));
  }
| CONSTANTF  {
  $$ = malloc(sizeof(struct generation));
  char *var_tmp = new_var();
  $$->name = new_var();
  $$->t = FLOATING;
  asprintf(&($$->code),"%s = fadd double %s, %s\n", var_tmp, double_to_hex_str(0.0), double_to_hex_str($1));
  asprintf(&($$->code),"%s%s = alloca double\n", $$->code, $$->name);
  asprintf(&($$->code),"%s%s", $$->code, store_value(var_tmp, $$->name, FLOATING));
  }
| '(' expression ')'{
  $$ = $2;
  }
| IDENTIFIER '(' ')' {
  $$ = malloc(sizeof(struct generation));
  struct expression *tmp = map_with_name(func_name($1));
  if(tmp == NULL){
    asprintf(&err, "Error: %s function not define", $1);
    yyerror(err);
    return -1;
  }    
  $$->name = new_var();
  char *tmp_var = new_var();
  $$->t = tmp->t;
  if(call_function(tmp_var, tmp->val, "", tmp->t) != NULL){
    asprintf(&($$->code), "%s",call_function(tmp_var, tmp->val, "", tmp->t));
    asprintf(&($$->code), "%s%s", $$->code, store_value(tmp_var, $$->name, tmp->t));
  }
  else{ 
    yyerror("Type non pris en compte");
    return -1;
  }
  }
| IDENTIFIER '(' argument_expression_list ')'{
  $$ = malloc(sizeof(struct generation));
  $$->code = NULL;
  
  struct expression *tmp = map_with_name(func_name($1));
  
  
  if(tmp == NULL){
    asprintf(&err, "Error: %s function not define", $1);
    yyerror(err);
    return -1;
  }
  
  asprintf(&$3, "%s%c", $3, '\0');
  // Récupération des paramètres 
  int i=0;
  char *tmp_var ;
  char *l_param = NULL;
  int l=strlen($3);
  char *t = NULL;
  char *name = NULL;
  int type = 0;
  t = NULL;
  name = NULL;
  $$->code = NULL;
  enum type current;
  for (i = 0; i < l ; ++i){ 
    tmp_var = new_var();
    if($3[i] == ','){
      type = 0;
      i++;
      switch(current){
      case INTEGER:
	if ($$->code == NULL)
	  asprintf(&($$->code), "%s", load_value(tmp_var, name, INTEGER));
	else
	asprintf(&($$->code), "%s%s", $$->code, load_value(tmp_var, name, INTEGER));
      
	if(l_param == NULL)
	  asprintf(&l_param,"i32 %s",tmp_var);
	else
	asprintf(&l_param,"%s, i32 %s", l_param, tmp_var);
	break;
      case FLOATING:
	if($$->code == NULL)
	  asprintf(&($$->code), "%s", load_value(tmp_var, name, FLOATING));
	else
	  asprintf(&($$->code), "%s%s", $$->code, load_value(tmp_var, name, FLOATING));
      
	if(l_param == NULL)
	  asprintf(&l_param,"double %s",tmp_var);
	else
	  asprintf(&l_param,"%s, double %s", l_param, tmp_var);
	
	break;
      default:
	yyerror("Error\n");
	return -1;
      }
      t = NULL;
      name = NULL;
    }
    else if($3[i] == ' '){
      type = 1;
      if(strcmp(t,"i32") == 0)
	current = INTEGER;
      else if (strcmp (t, "double") == 0)
	current = FLOATING;
    }
    else
      if(type == 0){
	if(t == NULL)
	  asprintf(&t,"%c",$3[i]);
	else
	  asprintf(&t,"%s%c", t,$3[i]);
      }
      else{
	if(name == NULL)
	  asprintf(&name, "%c", $3[i]);
	else
	  asprintf(&name,"%s%c", name, $3[i]);
      }
    
  }
  switch(current){
  case INTEGER:
    if ($$->code == NULL)
      asprintf(&($$->code), "%s", load_value(tmp_var, name, INTEGER));
    else
      asprintf(&($$->code), "%s%s", $$->code, load_value(tmp_var, name, INTEGER));
    
    if(l_param == NULL)
      asprintf(&l_param,"i32 %s",tmp_var);
    else
      asprintf(&l_param,"%s, i32 %s", l_param, tmp_var);
    break;
  case FLOATING:
    if($$->code == NULL)
      asprintf(&($$->code), "%s", load_value(tmp_var, name, FLOATING));
    else
      asprintf(&($$->code), "%s%s", $$->code, load_value(tmp_var, name, FLOATING));
    
    if(l_param == NULL)
      asprintf(&l_param,"double %s",tmp_var);
    else
      asprintf(&l_param,"%s, double %s", l_param, tmp_var);
    break;
  default:
    yyerror("Error\n");
    return -1;
  }

  //Fin récupération parametre 
  $$->name = new_var();
  tmp_var = new_var();
  $$->t = tmp->t;
  
  if(call_function(tmp_var, tmp->val, l_param, tmp->t) != NULL){
    if($$->code != NULL)
      asprintf(&($$->code), "%s%s",$$->code, call_function(tmp_var, tmp->val, l_param, tmp->t));
    else
      asprintf(&($$->code), "%s",call_function(tmp_var, tmp->val, l_param, tmp->t));
    asprintf(&($$->code), "%s%s", $$->code, store_value(tmp_var, $$->name, $$->t));
  }
  else{
    yyerror("Type non pris en compte");
    return -1;
  }
  }
;

 
postfix_expression
: primary_expression {
  $$ = $1;
 }
| IDENTIFIER INC_OP {
  
  $$ = op_1($1,ADD_OP);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles");
    return -1;
  }
 }
| IDENTIFIER DEC_OP{
  
  $$ = op_1($1,SUB_OP);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles");
    return -1;
  }
  }
;

 
argument_expression_list
: expression{
  if(get_type($1->name, $1->t)!=NULL)
    asprintf(&$$,"%s",get_type($1->name, $1->t));
  else{
    yyerror("Type non pris en compte");
    return -1;
  }
  }
| argument_expression_list ',' expression{
  if(get_type($3->name, $3->t)!=NULL)
    asprintf(&$$,"%s, %s",$1, get_type($3->name, $3->t));
  else{ 
    yyerror("Type non pris en compte");
    return -1;
  }
  }
;


 
unary_expression
: postfix_expression{
  $$ = $1;
 }
| INC_OP IDENTIFIER {
  $$ = op_1($2, ADD_OP);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles");
    return -1;
  }
 }
| DEC_OP IDENTIFIER{
  $$ = op_1($2, SUB_OP);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles");
    return -1;
  }
 }
| unary_operator unary_expression{
  $$ = $2;
  char *tmp_var1 = new_var();  
  char *tmp_var2 = new_var();
  switch($$->t){
  case INTEGER :
    if($2->code == NULL){
      asprintf(&($$->code),"%s", load_value(tmp_var1, $2->name, INTEGER));
      asprintf(&($$->code),"%s%s = sub i32 0, %s\n", $$->code, tmp_var2, tmp_var1);
      asprintf(&($$->code),"%s%s", $$->code, store_value(tmp_var2, $2->name, INTEGER));
    }
    else{
      asprintf(&($$->code),"%s%s", $2->code, load_value(tmp_var1, $2->name, INTEGER));
      asprintf(&($$->code),"%s%s = sub i32 0, %s\n", $$->code, tmp_var2, tmp_var1);
      asprintf(&($$->code),"%s%s", $$->code, store_value(tmp_var2, $2->name, INTEGER));
    }
    break;
  case FLOATING:
    if ($2->code == NULL){
      asprintf(&($$->code),"%s", load_value(tmp_var1, $2->name, FLOATING));
      asprintf(&($$->code),"%s%s = fsub double %s, %s\n",$$->code, tmp_var2, double_to_hex_str(0.0), tmp_var1);
      asprintf(&($$->code),"%s%s", $$->code, store_value(tmp_var2, $2->name, INTEGER));
    }
    else{
      asprintf(&($$->code),"%s%s", $2->code, load_value(tmp_var1, $2->name, FLOATING));
      asprintf(&($$->code),"%s%s = fsub double %s, %s\n",$$->code, tmp_var2, double_to_hex_str(0.0), tmp_var1);
      asprintf(&($$->code),"%s%s", $$->code, store_value(tmp_var2, $2->name, INTEGER));
    }
    break;
  default:
    yyerror("Impossible de rendre négatif, type incompatible");
    return -1;
  }
 }
;

 
unary_operator
: '-'
;

 
multiplicative_expression
: unary_expression{
  $$ = $1;
 }
| multiplicative_expression '*' unary_expression {
  $$ = operation_expression($1, $3, MUL_OP, 0);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles test");
    return -1;
  }
  }
| multiplicative_expression '/' unary_expression{
  $$ = operation_expression($1, $3, DIV_OP, 0);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles");
    return -1;
  }  
  }
| multiplicative_expression REM unary_expression{
  $$ = operation_expression($1, $3, REM_OP, 0);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles");
    return -1;
  }
 }
;

 
additive_expression
: multiplicative_expression{
  $$ = $1;
 }
| additive_expression '+' multiplicative_expression{
  $$ = operation_expression($1, $3, ADD_OP, 0);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles");
    return -1;
  }
  }
| additive_expression '-' multiplicative_expression{
  $$ = operation_expression($1, $3, SUB_OP, 0);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles");
    return -1;
  }  
  }
;

 
comparison_expression
: shift_expression{
  $$ = $1;
 }
| comparison_expression '<' shift_expression{
  $$ = operation_expression($1, $3, L_COMP, 1);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles");
    return -1;
  }
  }
| comparison_expression '>' shift_expression{
  $$ = operation_expression($1, $3, G_COMP, 1);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles");
    return -1;
  }  
  }
| comparison_expression LE_OP shift_expression{
  $$ = operation_expression($1, $3, LE_COMP, 1);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
    return -1;
  } 
 }
| comparison_expression GE_OP shift_expression{
  $$ = operation_expression($1, $3, GE_COMP, 1);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
    return -1;
  }
 }
| comparison_expression EQ_OP shift_expression{
  $$ = operation_expression($1, $3, EQ_COMP, 1);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
    return -1;
  }
 }
| comparison_expression NE_OP shift_expression{
  $$ = operation_expression($1, $3, NE_COMP, 1);
  if($$ == NULL){
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
    return -1;
  } 
 }
;

 
expression
: unary_expression assignment_operator conditional_expression{
  $$ = operation_expression($1, $3, string_to_op_code($2), 0);
  if($$ != NULL){
    if(store_value($3->name, $1->name, $$->t) != NULL)
      asprintf(&($$->code), "%s%s",$$->code,store_value($3->name, $1->name, $$->t));
    else{
      yyerror("Erreur de type : stockage impossible");
      return -1;
    }
  }
  else{
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
    return -1;
  }
 }
| conditional_expression{
  $$ = $1;
  }
;

 
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

 
declaration
: type_name declarator_list ';'{
  int length_l = length_llist($2);
  $$ = NULL;
  int i = 0;
  struct expression *tmp;
  for(; i<length_l; i++){
    tmp = look_for($2, i);
    init_exp(tmp, new_var(tmp->name), string_to_type($1), level);
    if(g_hash_table_contains(hash_array[level], tmp->name)){
      yyerror(&err, "Redéclaration de la variable %s", tmp->name);
      return -1;
    }
    else
      g_hash_table_insert(hash_array[level], tmp->name, tmp);
    switch(string_to_type($1)){
    case INTEGER:
      if($$ != NULL)
	asprintf(&$$,"%s%s = alloca i32\n", $$,tmp->val);
      else
	asprintf(&$$,"%s = alloca i32\n",tmp->val);
      break;
    case FLOATING:
      if ($$ != NULL)
	asprintf(&$$, "%s%s = alloca double\n",$$, tmp->val);
      else
	asprintf(&$$, "%s = alloca double\n", tmp->val);
      break;
    default:
      yyerror("Impossible de déclarer une variable qui n'est ni un double, ni un entier");
      return -1;
    }
  }
  
 }
;

 

declarator_list
: declarator{
  $$ = init_llist();
  add_llist($$, $1);
 }
| declarator_list ',' declarator{
  $$ = $1;
  add_llist($$, $3);
  }
;

 
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

 
//GESTION TABLE DE HASH
//GENERATION CODE
function_declarator
: declarator '(' parameter_list ')'{
  $$ = $1;
  init_function($$, new_func($$->name), last_type, $3);
  struct expression *tmp;
  if(!g_hash_table_contains(hash_array[level], func_name($1->name)))
    g_hash_table_insert(hash_array[level], func_name($1->name), $$);
  
  int i = 0;
  for(; i < length_llist($3); ++i){
    tmp = look_for($3, i);
    if(tmp->t != VOID_T){
      if(nb_occ($3, tmp->name) != 1){
	asprintf(&err, "Error: param %s already initialize\n", tmp->name);
	yyerror(err);
	return -1;
      }
      if(!g_hash_table_contains(hash_array[level],new_param(tmp->name)))
	g_hash_table_insert(hash_array[level], new_param(tmp->name),tmp);
    }
    else{
      asprintf(&err,"Error:impossible to have void parameter :%s", tmp->name);
      yyerror(err);
      return -1;
    }
  }
 }
| declarator '(' ')'{
  $$ = $1;
  init_function($$, new_func($$->name), last_type, NULL);
  if(!g_hash_table_contains(hash_array[level], func_name($1->name)))
    g_hash_table_insert(hash_array[level], func_name($1->name), $$);
  }
;

 
//GESTION TABLE HASH
//GENERATION CODE
declarator
: IDENTIFIER {
  $$ = create_non_init_exp($1);
 }
| '(' declarator ')'{
  $$ = $2;
  }
| declarator '(' parameter_list ')'{
    $$ = $1;
    struct expression *tmp;
    init_function($$, new_func($$->name), last_type, $3);
    if(!g_hash_table_contains(hash_array[level], func_name($1->name)))
      g_hash_table_insert(hash_array[level], func_name($1->name), $$);
    int i = 0;
    for(; i < length_llist($3); ++i){
      tmp = look_for($3, i);
      if(tmp->t != VOID_T){
	if(nb_occ($3, tmp->name) != 1){
	  asprintf(&err, "Error: param %s already initialize\n", tmp->name);
	  yyerror(err);
	  return -1;
	}
	if(!g_hash_table_contains(hash_array[level],new_param(tmp->name)))
	  g_hash_table_insert(hash_array[level], new_param(tmp->name),tmp);
      }
      else{
	asprintf(&err,"Error:impossible to have void parameter :%s", tmp->name);
	yyerror(err);
	return -1;
      }
    }
  }
| declarator '(' ')'{
  $$ = $1;
  init_function($$, new_func($$->name), last_type, NULL);
  if(!g_hash_table_contains(hash_array[level], func_name($1->name)))
    g_hash_table_insert(hash_array[level], func_name($1->name), $$);
  }
;
  


 
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

 
parameter_declaration
: type_name declarator{
  $$ = $2;
  init_exp($$, new_param($$->name), string_to_type($1), level);
 }
;

 
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

 
RB : '}'{
  g_hash_table_foreach(hash_array[level], value, NULL);
  level--;
 }
;

 
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

 
compound_stat
: statement_list {
  $$ = $1;
 }
| statement_list compound_dec{
  asprintf(&$$,"%s%s", $1, $2);
 }
;

 
compound_dec
: declaration_list{
  if($1 != NULL)
    $$ = $1;
 }
| declaration_list compound_stat{
  if($1 != NULL)
    asprintf(&$$, "%s%s", $1, $2);
  else
    asprintf(&$$, "%s", $2);
 }
;

 
declaration_list
: declaration {
  if ($1 != NULL)
    $$ = $1;
 }
| declaration_list declaration{
  if($2 != NULL)
    asprintf(&$$,"%s%s", $1, $2);
  else
    if($1 != NULL)
      asprintf(&$$,"%s", $1);
 }
;

 
statement_list
: statement{
  $$ = $1;
 }
| statement_list statement{
  asprintf(&$$,"%s%s", $1, $2);
 }
;

 
expression_statement
: ';'
{
  $$ = NULL;
}
| expression ';'{
  $$ = $1->code;
  }
;

 
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

 
iteration_statement
: WHILE '(' expression ')' statement{
  $$ = for_expression(NULL, $3->code, NULL, $5);
 }
| DO statement WHILE '(' expression ')' ';'{
  asprintf(&$$,"%s%s", $2,for_expression(NULL, $5->code, NULL, $2));
 }
;

 
jump_statement
: RETURN ';'{
  if(return_expression(VOID_T, NULL, NULL) != NULL)
    $$ = return_expression(VOID_T, NULL, NULL);
  else{
    yyerror("Type non pris en compte");
    return -1;
  }
 }
| RETURN expression ';'{
  if(return_expression($2->t, $2->name, $2->code) != NULL)
    $$ = return_expression($2->t, $2->name, $2->code);
  else{
    yyerror("Type non pris en compte");
    return -1;
  }
 }
;

 
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

 
external_declaration
: function_definition{
  $$ = $1;
 }
| declaration{
  $$ = $1;
  }
;

 
function_definition
: type_name function_declarator compound_statement{
  $2->t = string_to_type($1);
  $2->level = level;
  switch($2->t){
    
  case INTEGER:
    if(parameter_to_string($2) != NULL || $2->param == NULL)
      if ($2->param == NULL)
	asprintf(&$$,"define i32 %s(){\n", new_func($2->name));
      else{
	asprintf(&$$,"define i32 %s(%s){\n", new_func($2->name), parameter_to_string($2));
	
      }
    else{
      yyerror("Type non pris en compte");
      return -1;
    }
    break;
  case FLOATING:
    if(parameter_to_string($2) != NULL || $2->param == NULL)
      if ($2->param == NULL)
	asprintf(&$$,"define i32 %s(){\n", new_func($2->name));
      else{
	asprintf(&$$,"define double %s(%s){\n", new_func($2->name), parameter_to_string($2));
      }
    else{
      yyerror("Type non pris en compte");
      return -1;
    }
    break;
  case VOID_T:
    if(parameter_to_string($2) != NULL || $2->param == NULL )
      if ($2->param == NULL)
	asprintf(&$$,"define i32 %s(){\n", new_func($2->name));
      else{
	asprintf(&$$,"define void %s(%s){\n", new_func($2->name), parameter_to_string($2));
      }
    else{
      yyerror("Type non pris en compte");
      return -1;
    }
      break;
  default:
    yyerror("Type booléen ou non défini ne peuvent pas etre le type de retour d'une fonction");
    return -1;
  }
  
  remove_param_hash_table($2);
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
  insert_declaration(hash_array[level]);
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

  asprintf(&code, "declare double @cos(double)\n%s",code);
  asprintf(&code, "declare double @sin(double)\n%s",code);
  asprintf(&code, "declare double @log10(double)\n%s",code);
  asprintf(&code, "declare double @sqrt(double)\n%s",code);
  asprintf(&code, "declare void @point(double, double)\n%s",code);
  asprintf(&code, "declare void @line(double, double, double, double)\n%s",code);
  asprintf(&code, "declare void @ellipse(double, double, double, double)\n%s", code);
  asprintf(&code, "declare void @fill(double)\n%s", code);
  asprintf(&code, "declare void @stroke(double)\n%s", code);
  asprintf(&code, "declare void @background(double)\n%s", code);
  asprintf(&code, "declare void @createCanvas(double, double)\n%s",code);


  FILE *output = NULL;
  output=fopen("convert.ll","w");

  if(output != NULL)
    fputs(code,output);
  else{
    yyerror("Erreur creation fichier");
    return -1;
  }
  
  free (file_name);

  i = 0;
  for(; i < max_hash ; i++)
    if(hash_array[i] != NULL){
      g_hash_table_destroy(hash_array[i]);
    }
  free(hash_array);

  
  return 0;
}
