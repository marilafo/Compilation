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
  char *last_id;
};

char *err;
  
//Niveau pour les déclarations de variables
int level;

//Compteurs variables temporaire
int num_var = 0;

//Compteurs de label
int num_label = 0;

enum type last_type;

int max_hash = 10;
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

GHashTable ** hash_array;

struct expression *tmp;



//Function to create a new var with a correct name
char *new_var(){
  char *s;
  asprintf(&s,"%%x%d", num_var);
  num_var++;
  return s;
}

char *new_func(char *function){
  char *s;
  asprintf(&s, "@%s_func", function);
  return s;
}

char *new_param(char *name){
  char *s;
  asprintf(&s,"%s_param", name);
  return s;
}

char *new_label(){
  char *s;
  asprintf(&s,"l%d", num_label);
  num_label++;
  return s;
}

char *get_type(char *name, enum type t){
  char *ret;
  switch(t){
  case INTEGER:
    asprintf(&ret, "i32 %s", name);
    break;
  case FLOATING:
    asprintf(&ret, "double %s", name);
    break;
  default:
    return NULL;
  }
  return ret;
}
struct expression *map_symbol(char *name, enum type t){
  struct expression *old;
  int i = level;
  for(; i > 0; --i){
    if( g_hash_table_contains(hash_array[i], name)){
      old = g_hash_table_lookup(hash_array[i], name);
      if(old->t == t)
	return old;
    }
    else if (g_hash_table_contains(hash_array[i], new_param(name))){
      old = g_hash_table_lookup(hash_array[i], new_param(name));
      if(old->t == t)
	return old;
    }
  }
    
  return NULL;
}

struct expression *map_with_name(char *name){
 struct expression *old;
  int i = level;
  for(; i >= 0; --i){
    if( g_hash_table_contains(hash_array[i], name)){
      old = g_hash_table_lookup(hash_array[i], name);
      return old;
    }
    else if (g_hash_table_contains(hash_array[i], new_param(name))){
      old = g_hash_table_lookup(hash_array[i], new_param(name));
      return old;
    }
  }
  return NULL;
}

void print_hash(gpointer key, gpointer value, gpointer user_data){
  printf("key :%s\n",(char *)key);
}
  

void value(gpointer key, gpointer value, gpointer user_data){
  struct expression *old;
  struct expression *v = (struct expression *)value;
  if(v->level == -1){
    old = NULL;
    old = map_symbol((char *)key, v->t);
    if(old != NULL){
      old->val = v->val;
    }
  }
 
}

struct expression * action_identifier(char *name){
  struct expression *ret;
  enum type t;
  if(g_hash_table_contains(hash_array[level], name)){
    ret = g_hash_table_lookup(hash_array[level], name);
    //asprintf(&($$->code),"%s", load_value($$->name, tmp->val, tmp->t));	      
  }
  else{
    tmp = map_with_name(name);
    if(tmp==NULL)
      t = last_type;
    ret = create_exp(name, new_var(), t, -1);
    g_hash_table_insert(hash_array[level], name, ret);
  }
  return ret;

}

char *call_function(char *var, char *fun, char *arg ,enum type t){
  char *ret;
  switch(t){
  case INTEGER:
    asprintf(&ret, "%s = call i32 @%s(%s)\n", var, fun, arg);
    break;
  case FLOATING:
    asprintf(&ret, "%s = call double @%s(%s)\n", var, fun, arg);
    break;
  case VOID_T:
    asprintf(&ret, "call void @%s(%s) noreturn\n", fun, arg);
    break;
  default:
    return NULL;
  }
  return ret;
}
    
/*
char *load_value(char *res, char* var, enum type t){
  char *ret;
  switch(t){
  case INTEGER:
    asprintf(&ret,"%s = load i32, i32* %s\n", res, var);
    break;
  case FLOATING:
    asprintf(&ret,"%s = load double, double* %s \n", res, var);
    break;
  default:
    return NULL;
  }
  return ret;
}
*/

/*
char *store_value(char *var, char* ptr, enum type t){
  char *ret;
  switch(t){
  case INTEGER:
    asprintf(&ret, "store i32 %s, i32* %s\n", var, ptr);
    break;
  case FLOATING:
    asprintf(&ret, "store double %s, double* %s\n", var, ptr);
    break;
  default:
    return NULL;
  }
  return ret;
	    
}
*/

char *made_op_int(char *res, char *arg1, char *arg2, enum operation_code op){
  char *ret;
  switch(op){
  case ADD_OP:
    asprintf(&ret,"%s = add i32 %s, %s\n", res, arg1, arg2);
    break;
  case SUB_OP:
    asprintf(&ret,"%s = sub i32 %s, %s\n", res, arg1, arg2);
    break;
  case MUL_OP:
    asprintf(&ret,"%s = mul i32 %s, %s\n", res, arg1, arg2);
    break;
  case DIV_OP:
    asprintf(&ret,"%s = sdiv i32 %s, %s\n", res, arg1, arg2);
    break;
  case REM_OP:
    asprintf(&ret,"%s = srem i32 %s, %s\n", res, arg1, arg2);
    break;
  case ASS_OP:
    asprintf(&ret,NULL);
    break;
  case SHL_OP:
    asprintf(&ret,"%s = shl i32 %s, %s\n", res, arg1, arg2);
    break;
  case SHR_OP:
    asprintf(&ret,"%s = lshr i32 %s, %s\n", res, arg1, arg2);
    break;
  case AND_OP:
    asprintf(&ret,"%s = and i32 %s, %s\n", res, arg1, arg2);
    break;
  case OR_OP:
    asprintf(&ret,"%s = or i32 %s, %s\n", res, arg1, arg2);
    break;
  default:
    return NULL;
  }
  return ret;
	
}

char *made_op_double(char *res, char *arg1, char *arg2, enum operation_code op){
  char *ret;
  switch(op){
  case ADD_OP:
    asprintf(&ret,"%s = fadd double %s, %s \n",res, arg1, arg2);
    break;
  case SUB_OP:
    asprintf(&ret,"%s = fsub double %s, %s \n",res, arg1, arg2);
    break;
  case MUL_OP:
    asprintf(&ret,"%s = fmul double %s, %s\n", res, arg1, arg2);
    break;
  case DIV_OP:
    asprintf(&ret,"%s = fdiv double %s, %s\n", res, arg1, arg2);
    break;
  case REM_OP:
    asprintf(&ret,"%s = srem double %s, %s\n", res, arg1, arg2);
    break;
  case ASS_OP:
    asprintf(&ret,NULL);
    break;
    /*case SHL_OP:
    printf("Error on ne peut pas SHL avec un double\n");
    break;
  case SHR_OP:
    printf("Error on ne peut pas SHR avec un double\n");
    break;
  case AND_OP:
    printf("Error on ne peut pas AND avec un double\n");
    break;
  case OR_OP:
    printf("Error on ne peut pas OR avec un double\n");
    break;*/
  default:
    return NULL;

  }
  return ret;
}

char *made_comparison_int(char *res, char *arg1, char *arg2, enum operation_code comp){
  char *ret;
  switch(comp){
  case L_COMP:
    asprintf(&ret,"%s = icmp slt i32 %s, %s", res, arg1, arg2); 
    break;
  case G_COMP:
    asprintf(&ret,"%s = icmp sgt i32 %s, %s", res, arg1, arg2);
    break;
  case LE_COMP:
    asprintf(&ret,"%s = icmp sle i32 %s, %s", res, arg1, arg2);
    break;
  case GE_COMP:
    asprintf(&ret,"%s = icmp sge i32 %s, %s", res, arg1, arg2);
    break;
  case EQ_COMP:
    asprintf(&ret,"%s = icmp eq i32 %s, %s", res, arg1, arg2);
    break;
  case NE_COMP:
    asprintf(&ret,"%s = icmp ne i32 %s, %s", res, arg1, arg2);
    break;
  default:
    return NULL;
  }
  return ret;
}

char *made_comparison_double(char *res, char *arg1, char *arg2, enum operation_code comp){
  char *ret;
  switch(comp){
  case L_COMP:
    asprintf(&ret,"%s = fcmp ult double %s, %s", res, arg1, arg2); 
    break;
  case G_COMP:
    asprintf(&ret,"%s = fcmp ugt double %s, %s", res, arg1, arg2);
    break;
  case LE_COMP:
    asprintf(&ret,"%s = fcmp ule double %s, %s", res, arg1, arg2);
    break;
  case GE_COMP:
    asprintf(&ret,"%s = fcmp uge double %s, %s", res, arg1, arg2);
    break;
  case EQ_COMP:
    asprintf(&ret,"%s = fcmp ueq double %s, %s", res, arg1, arg2);
    break;
  case NE_COMP:
    asprintf(&ret,"%s = fcmp une double %s, %s", res, arg1, arg2);
    break;
  default:
    return NULL;
  }
  return ret;
}




struct generation *op_1(char *name, enum operation_code op ){
  struct generation *ret = malloc (sizeof(struct generation));
  tmp = action_identifier(name);
  ret->name = tmp->val;    
  ret->t = tmp->t;
  ret->last_id = name;
  //asprintf(&(ret->code),"%s", load_value(ret->name, tmp->val, tmp->t));
  switch(tmp->t){
  case INTEGER:
    if(made_op_int(ret->name, ret->name, "1", op)==NULL)
      return NULL;
    else
      asprintf(&(ret->code),"%s", made_op_int(ret->name, ret->name, "1", op));    
    break;
  case FLOATING:
    if(made_op_double(ret->name, ret->name,double_to_hex_str(1.0),op) == NULL)
      return NULL;
    else
      asprintf(&(ret->code),"%s", made_op_double(ret->name, ret->name,double_to_hex_str(1.0),op));
        
    break;
  case VOID_T:
    //printf("++/-- invalide avec type void\n");
    return NULL;
    break;
  case BOOL_T:
    //printf("++/-- invalide avec type booleen\n");
    return NULL;
    break;
  case NOT_DEFINE:
    //printf("++/-- invalide variable non défini\n");
    return NULL;
    break;
  }
  //asprintf(&(ret->code),"%s",store_value(ret->name, tmp->val, tmp->t));
  return ret;
}

struct generation *operation_expression(struct generation *a, struct generation *b, enum operation_code c, int made_code){
  struct generation *ret = malloc(sizeof(struct generation));
  ret->name = new_var();
  if(a->t == INTEGER && b->t == INTEGER){
    ret->t = a->t;
    asprintf(&(ret->code), "%s%s", a->code, b->code);
    if (made_code == 0){
      if(made_op_int(ret->name, a->name, b->name ,c) == NULL)
	return NULL;
      else
	asprintf(&(ret->code), "%s%s",ret->code, made_op_int(ret->name, a->name, b->name ,c));
    }
    else if (made_code == 1)
      if(made_comparison_int(ret->name, a->name, b->name ,c) != NULL)
	asprintf(&(ret->code), "%s%s", ret->code, made_comparison_int(ret->name, a->name, b->name ,c));
    return NULL;
  }
  else if (a->t == FLOATING && b->t == FLOATING){
    ret->t = a->t;
    asprintf(&(ret->code), "%s%s", a->code, b->code);
    if(made_code == 0)
      if(made_op_double(ret->name, a->name, b->name, c) == NULL)
	return NULL;
      else
	asprintf(&(ret->code), "%s%s",ret->code, made_op_double(ret->name, a->name, b->name, c));
    else if (made_code == 1){
      if(made_comparison_double(ret->name, a->name, b->name, c) != NULL)
	asprintf(&(ret->code), "%s%s",ret->code, made_comparison_double(ret->name, a->name, b->name, c));
      else 
	return NULL;
    }
  }
  else{
    return NULL;
  }
  if(c == L_COMP || c == G_COMP || c == LE_COMP || c == GE_COMP || c == EQ_COMP || c == NE_COMP)
    ret->t = BOOL_T;
  return ret;
}

char * if_expression(char *var, char *cond, char *t, char *f){
  char *ret;
  char *l_t = new_label();
  char *l_f = new_label();
  asprintf(&ret, "%s", cond);
  asprintf(&ret, "%sbr i1 %s, label %%%s, label %%%s\n",ret, var, l_t, l_f);
  asprintf(&ret, "%s%s:\n%s", ret, l_t,t);
  asprintf(&ret, "%s%s:\n",ret, l_f);
  asprintf(&ret, "%s%s\n", ret,f);
  return ret;
}

char * for_expression(char *init, char *inc, struct generation *cond, char * b){
  char * ret;
  char *boucle = new_label();
  char *fin = new_label();
  asprintf(&ret, "%s", init);
  if(cond == NULL)
    asprintf(&ret, "%sbr label %%%s\n",ret, boucle);
  else
    asprintf(&ret, "%sbr i1 %s label %%%s, label %%%s\n", ret, cond->name, boucle, fin);
    
  asprintf(&ret, "%s%s:\n",ret, boucle);
  asprintf(&ret, "%s%s", ret, b);
  asprintf(&ret, "%s%s", ret,inc);
  if (cond != NULL)
    asprintf(&ret, "%s%s", ret, cond->code);

  if(cond == NULL)
    asprintf(&ret, "%sbr label %%%s\n",ret, boucle);
  else
    asprintf(&ret, "%sbr i1 %s label %%%s, label %%%s\n", ret, cond->name, boucle, fin);

  asprintf(&ret, "%s%s:\n", ret, fin);
  return ret;
}

char *return_expression(enum type t, char* var){
  char *ret;
  switch(t){
  case INTEGER:
    asprintf(&ret,"ret i32 %s\n", var);
    break;
  case FLOATING:
    asprintf(&ret,"ret double %s\n", var);
    break;
  case VOID_T:
    asprintf(&ret,"ret void");
  default:
    return NULL;
  }
 
  return ret;
}

enum operation_code string_to_op_code(char *s){
  if(strcmp("ass", s) == 0)
    return ASS_OP;
  else if (strcmp("mul", s) == 0)
    return MUL_OP;
  else if (strcmp("div", s) == 0)
    return DIV_OP;
  else if (strcmp("rem", s) == 0)
    return REM_OP;
  else if (strcmp("shl", s) == 0)
    return SHL_OP;
  else if (strcmp("shr", s) == 0)
    return SHR_OP;
  else if (strcmp("add", s) == 0)
    return ADD_OP;
  else if (strcmp("sub", s) == 0)
    return SUB_OP;
  return -1;
}

enum type string_to_type(char *s){
  if(strcmp("int", s) == 0)
    return INTEGER;
  if(strcmp("double", s) == 0)
    return FLOATING;
  if(strcmp("void", s) == 0)
    return VOID_T;
  return -1;
}

char *parameter_to_string(struct expression *e){
  int i = 0;
  char *ret;
  struct expression *param;
  for(; i < e->size_param; i++){
    param = look_for(e->param, i);
    switch(param->t){
    case INTEGER:
      asprintf(&ret,", i32 %s",param->name);
      break;
    case FLOATING:
      asprintf(&ret,", double %s",param->name); 
    default:
      return NULL;
    }    
  }
  return ret;
}
