%{
    #define _GNU_SOURCE
    #include <stdio.h>
    #include <search.h>
    #include "identificateur.h"
    #include "double_to_hex.c"
    #include "code.c"
  
  
  //A enlever quand on aura les listes
  //int tab = 0;
  //int p = 0;
  
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
  $$ = operation_expression($1, $3, OR_OP, 0);
 }
;

//DONE
logical_and_expression
: comparison_expression{
  $$ = $1;
 }
| logical_and_expression AND comparison_expression{
  $$ = operation_expression($1, $3, AND_OP, 0);
 }
;

//DONE
shift_expression
: additive_expression{
  $$ = $1;
 }
| shift_expression SHL additive_expression{
  $$ = operation_expression($1, $3, SHL_OP, 0);
 }
| shift_expression SHR additive_expression{
  $$ = operation_expression($1, $3, SHR_OP, 0);
 }
;

//DOING
primary_expression
: IDENTIFIER {
  $$ = malloc(sizeof(struct generation));
  if(is_in_hash_table(key_name($1,level))){
      $$->name = tmp->val;
      get_hash_table(tmp, $1);
      $$->t = tmp->t;
      //asprintf(&($$->code),"%s", load_value($$->name, tmp->val, tmp->t));	      
    }
    else{
      $$->name = new_var();
      $$->t = NOT_DEFINE;
      tmp = create_non_init_exp($1);
      tmp->val = $$->name;
      tmp->t = NOT_DEFINE;
      tmp->size_param = -1;
      add_hash_table(tmp);
    }
    asprintf(&($$->code), "%s", $$->name);
    printf("%s", $$->name);
      
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
    $$ = malloc(sizeof(struct generation));
    $$->name = new_var();
    get_hash_table(tmp, function_name($1));
    $$->t = tmp->t;
    asprintf(&($$->code), "%s", call_function($$->name, tmp->val, "", tmp->t));
  }
| IDENTIFIER '(' argument_expression_list ')'{
    $$ = malloc(sizeof(struct generation));
    $$->name = new_var();
    get_hash_table(tmp, function_name($1));
    $$->t = tmp->t;
    asprintf(&($$->code), "%s", call_function($$->name, tmp->val, $3, tmp->t));
  }
;

//DOING
postfix_expression
: primary_expression {
  $$ = $1;
 }
| IDENTIFIER INC_OP {
  $$ = op_1($1,ADD_OP);
 }
| IDENTIFIER DEC_OP{
  $$ = op_1($1,SUB_OP);
 }
;

//DOING
argument_expression_list
: expression{
  asprintf(&$$,"%s",get_type($1->name, $1->t));
 }
| argument_expression_list ',' expression{
  asprintf(&$$, "%s, ", $1);
  asprintf(&$$,"%s",get_type($3->name, $3->t));
  }
;
//DOING
unary_expression
: postfix_expression{
  $$ = $1;
 }
| INC_OP IDENTIFIER {
  $$ = op_1($2, ADD_OP);
 }
| DEC_OP IDENTIFIER{
  $$ = op_1($2, SUB_OP);
 }
| unary_operator unary_expression{
    $$->name = new_var();
    $$->t = $2->t;
    switch($$->t){
    case INTEGER :
      asprintf(&($$->code),"%s", $2->code);
      asprintf(&($$->code),"%s = sub i32 0, %s\n", $$->name, $2->name);
      break;
    case FLOATING:
      asprintf(&($$->code),"%s", $2->code);
      asprintf(&($$->code),"%s = fsub double %s, %s\n", $$->name, double_to_hex_str(0.0), $2->name);
      break;
    default:
      printf("Error l.278\n");
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
  $$ = operation_expression($1, $3, MUL_OP, 0);
  }
| multiplicative_expression '/' unary_expression{
  $$ = operation_expression($1, $3, DIV_OP, 0);
  }
| multiplicative_expression REM unary_expression{
  $$ = operation_expression($1, $3, REM_OP, 0);
 }
;

//DOING
additive_expression
: multiplicative_expression{
    $$ = $1;
 }
| additive_expression '+' multiplicative_expression{
  $$ = operation_expression($1, $3, ADD_OP, 0);
  }
| additive_expression '-' multiplicative_expression{
  $$ = operation_expression($1, $3, SUB_OP, 0);
  }
;

//DOING
comparison_expression
: shift_expression{
  $$ = $1;
 }
| comparison_expression '<' shift_expression{
  $$ = operation_expression($1, $3, L_COMP, 1);
  }
| comparison_expression '>' shift_expression{
  $$ = operation_expression($1, $3, G_COMP, 1);
  }
| comparison_expression LE_OP shift_expression{
  $$ = operation_expression($1, $3, LE_COMP, 1);
 }
| comparison_expression GE_OP shift_expression{
  $$ = operation_expression($1, $3, GE_COMP, 1);
 }
| comparison_expression EQ_OP shift_expression{
  $$ = operation_expression($1, $3, EQ_COMP, 1);
 }
| comparison_expression NE_OP shift_expression{
  $$ = operation_expression($1, $3, NE_COMP, 1);
 }
;

//DOING
expression
: unary_expression assignment_operator conditional_expression{
  if($1->t == NOT_DEFINE)
    add_type_elt($1->name, $3->t);
  $$ = operation_expression($1, $3, string_to_op_code($2), 0);
  asprintf(&($$->code), "%s",store_value($3->name, $1->name, $$->t)); 
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
  
  //Taille de la liste
  int i = 0;
  struct expression *tmp;
  for(; i<length_l; i++){
    tmp = look_for($2, i);
    tmp->t = string_to_type($1);
    tmp->level = level;
    add_hash_table(tmp);
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
 }
| INT{
  $$ = "int";
  }
| DOUBLE{
  $$ = "double";
  }
;

//DOING
//GESTION TABLE DE HASH
//GENERATION CODE
function_declarator
: declarator '(' parameter_list ')'{
  $$ = $1;
  init_function($$, VOID_T, NULL, $3);
 }
| declarator '(' ')'{
  $$ = $1;
  init_function($$, VOID_T, NULL, NULL);
  }
;

//DOING
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
  init_function($$, VOID_T, NULL, $3);
  }
| declarator '(' ')'{
  $$ = $1;
  init_function($$, VOID_T, NULL, NULL);
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
  if(string_to_type($1) != VOID_T)
    init_exp($$, NULL, string_to_type($1));
  else
    printf("Error\n");
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
}
;

//DOING
RB : '}'{
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
  asprintf(&$$,"%s", $2);
  asprintf(&$$,"%s", for_expression(NULL, $5->code, NULL, $2));
 }
;

//DOING
jump_statement
: RETURN ';'{
  $$ = return_expression(VOID_T, NULL);
 }
| RETURN expression ';'{
  $$ = return_expression($2->t, $2->name);
 }
;

//DOING
program
: external_declaration{
  $$ = $1;
  printf("%s\n", $$);
 }
| program external_declaration{
  asprintf(&$$, "%s%s", $1, $2);
  printf("%s\n", $$);
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
  printf("Coucou\n");
  $2->t = string_to_type($1);
  $2->level = level;
  add_hash_table($2);
  switch($2->t){
  case INTEGER:
    asprintf(&$$,"define i32 @%s(%s){", function_name($2->name), parameter_to_string($2));
    break;
  case FLOATING:
    asprintf(&$$,"define double @%s(%s){", function_name($2->name), parameter_to_string($2));
    break;
  case VOID_T:
    asprintf(&$$,"define void @%s(%s){", function_name($2->name), parameter_to_string($2));
    break;
  default:
    printf("Error\n");
  }
 
  asprintf(&$$,"%s", $3);
  asprintf(&$$,"}");
  
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
  //char *tab[length_hash];
  hcreate(length_hash);
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
    hdestroy();
    free (file_name);
    
    return 0;
}
