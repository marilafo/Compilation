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




//Function to create a new var with a correct name
char *new_var(){
  char *s;
  asprintf(&s,"%%x%d", num_var);
  num_var++;
  return s;
}

char *func_name(char *function){
  char *s;
  asprintf(&s, "%s_func", function);
  return s;
}

char *new_func(char *function){
  char *s;
  asprintf(&s, "@%s", function);
  return s;
}

char *new_param(char *name){
  char *s;
  asprintf(&s,"%%%s_param", name);
  return s;
}

char *new_global(char *name){
  char *s;
  asprintf(&s, "@%s", name);
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

void print_hash(gpointer key, gpointer value, gpointer user_data){
  printf("key :%s\n",(char *)key);
}
  


char *load_value(char *res, char* var, enum type t){
  char *ret = NULL;
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

struct expression *map_symbol(char *name, enum type t){
  struct expression *old;
  int i = level;
  for(; i > 0; --i){
    
    if(i == 0){
      if (g_hash_table_contains(hash_array[i], new_param(name))){
	old = g_hash_table_lookup(hash_array[i], new_param(name));
	return old;
      }
    }
    if( g_hash_table_contains(hash_array[i], name)){
      old = g_hash_table_lookup(hash_array[i], name);
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
    if(i == 0){
      if (g_hash_table_contains(hash_array[i], new_param(name))){
	old = g_hash_table_lookup(hash_array[i], new_param(name));
	return old;
      }
    }
    if( g_hash_table_contains(hash_array[i], name)){
      old = g_hash_table_lookup(hash_array[i], name);
      return old;
    }
  }
  return NULL;
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

struct exp_code action_identifier(char *name){
  struct expression *ret;
  char *code = NULL;
  char *tmp_var;
  struct expression *old;
  if(g_hash_table_contains(hash_array[level], name)){
    ret = g_hash_table_lookup(hash_array[level], name);
  }
  else{
    
    int i = level;
    for(; i >= 0; --i){
      printf("Hash level %d:\n", i);
      g_hash_table_foreach(hash_array[i], print_hash, NULL);
      printf("\n");
      if(i == 0){
	if (g_hash_table_contains(hash_array[i], new_param(name))){
	  printf("Coucou\n");
	  old = g_hash_table_lookup(hash_array[i], new_param(name));
	  ret= old;
	  tmp_var = new_var();
	  if(ret->t == INTEGER){
	    asprintf(&code, "%s = alloca i32\n", tmp_var);
	    printf("Hear\n");
	  }
	  else
	    asprintf(&code, "%s = alloca double\n",tmp_var);
	  asprintf(&code, "%s%s", code, store_value(ret->val, tmp_var, ret->t));
	}
      }
      if( g_hash_table_contains(hash_array[i], name)){
	old = g_hash_table_lookup(hash_array[i], name);
	ret = old;
	tmp_var = ret->val;
      }
    }

    ret = create_exp(name, tmp_var, ret->t, -1);
    g_hash_table_insert(hash_array[level], name, ret);
  }
  struct exp_code d;
  d.code = code;
  d.g = ret;
  return d;

}

char *call_function(char *var, char *fun, char *arg ,enum type t){
  char *ret;
  switch(t){
  case INTEGER:
    asprintf(&ret, "%s = call i32 %s(%s)\n", var, fun, arg);
    return ret;
    break;
  case FLOATING:
    asprintf(&ret, "%s = call double %s(%s)\n", var, fun, arg);
    return ret;
    break;
  case VOID_T:
    asprintf(&ret, "call void %s(%s) noreturn\n", fun, arg);
    return ret;
    break;
  default:
    return NULL;
  }
  return ret;
}
    



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
  default:
    return NULL;

  }
  return ret;
}

char *made_comparison_int(char *res, char *arg1, char *arg2, enum operation_code comp){
  char *ret;
  switch(comp){
  case L_COMP:
    asprintf(&ret,"%s = icmp slt i32 %s, %s\n", res, arg1, arg2); 
    break;
  case G_COMP:
    asprintf(&ret,"%s = icmp sgt i32 %s, %s\n", res, arg1, arg2);
    break;
  case LE_COMP:
    asprintf(&ret,"%s = icmp sle i32 %s, %s\n", res, arg1, arg2);
    break;
  case GE_COMP:
    asprintf(&ret,"%s = icmp sge i32 %s, %s\n", res, arg1, arg2);
    break;
  case EQ_COMP:
    asprintf(&ret,"%s = icmp eq i32 %s, %s\n", res, arg1, arg2);
    break;
  case NE_COMP:
    asprintf(&ret,"%s = icmp ne i32 %s, %s\n", res, arg1, arg2);
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
    asprintf(&ret,"%s = fcmp ult double %s, %s\n", res, arg1, arg2); 
    break;
  case G_COMP:
    asprintf(&ret,"%s = fcmp ugt double %s, %s\n", res, arg1, arg2);
    break;
  case LE_COMP:
    asprintf(&ret,"%s = fcmp ule double %s, %s\n", res, arg1, arg2);
    break;
  case GE_COMP:
    asprintf(&ret,"%s = fcmp uge double %s, %s\n", res, arg1, arg2);
    break;
  case EQ_COMP:
    asprintf(&ret,"%s = fcmp ueq double %s, %s\n", res, arg1, arg2);
    break;
  case NE_COMP:
    asprintf(&ret,"%s = fcmp une double %s, %s\n", res, arg1, arg2);
    break;
  default:
    return NULL;
  }
  return ret;
}




struct generation *op_1(char *name, enum operation_code op ){
  struct generation *ret = malloc (sizeof(struct generation));
  struct exp_code d = action_identifier(name);
  struct expression *tmp = d.g;
  ret->name = tmp->val;
  ret->t = tmp->t;
  char *tmp_var = new_var();
  char *ret_var = new_var();
  if(d.code != NULL)
    asprintf(&(ret->code),"%s%s", d.code,load_value(tmp_var, tmp->val, tmp->t));
  else
    asprintf(&(ret->code),"%s", load_value(tmp_var, tmp->val, tmp->t));
  switch(tmp->t){
  case INTEGER:
    if(made_op_int(ret_var, tmp_var, "1", op)==NULL)
      return NULL;
    else
      asprintf(&(ret->code),"%s%s", ret->code, made_op_int(ret_var, tmp_var, "1", op));    
    break;
  case FLOATING:
    if(made_op_double(ret_var, tmp_var ,double_to_hex_str(1.0),op) == NULL)
      return NULL;
    else
      asprintf(&(ret->code),"%s%s", ret->code, made_op_double(ret_var, tmp_var,double_to_hex_str(1.0),op));
        
    break;
  case VOID_T:
    return NULL;
    break;
  case BOOL_T:
    return NULL;
    break;
  case NOT_DEFINE:
    return NULL;
    break;
  }
  asprintf(&(ret->code),"%s%s",ret->code, store_value(ret_var, ret->name, tmp->t));
  return ret;
}


void insert_previous_exp(struct generation *ret, struct generation *a, struct generation *b){
   if(a->code != NULL){
      asprintf(&(ret->code),"%s", a->code);
      if(b->code != NULL)
	asprintf(&(ret->code),"%s%s", ret->code, b->code);
    }
    else
      if(b->code != NULL)
	asprintf(&(ret->code),"%s", b->code);
}



struct generation *operation_expression(struct generation *a, struct generation *b, enum operation_code c, int made_code){
  struct generation *ret = malloc(sizeof(struct generation));
  ret->code = NULL;
  char *var_a = new_var();
  char *var_b = new_var();
  char *var_res = new_var();
  ret->name = new_var();
  if(a->t == INTEGER && b->t == INTEGER){
    ret->t = a->t;
    
    insert_previous_exp(ret, a, b);

    if(ret->code == NULL)
      asprintf(&(ret->code), "%s%s", load_value(var_a, a->name, a->t), load_value(var_b, b->name, b->t));
    else
      asprintf(&(ret->code), "%s%s%s", ret->code, load_value(var_a, a->name, a->t), load_value(var_b, b->name, b->t));
    
    if (made_code == 0){
      if(made_op_int(var_res, var_a, var_b, c) == NULL)
	return NULL;
      else{
	asprintf(&(ret->code), "%s%s",ret->code, made_op_int(var_res, var_a, var_b, c));
	asprintf(&(ret->code), "%s%s = alloca i32\n", ret->code, ret->name);
	asprintf(&(ret->code), "%s%s", ret->code, store_value(var_res, ret->name, INTEGER));
      }
    }
    else if (made_code == 1){
      if(made_comparison_int(var_res, var_a, var_b ,c) != NULL){
	asprintf(&(ret->code), "%s%s", ret->code, made_comparison_int(var_res, var_a, var_b ,c));
	asprintf(&(ret->code), "%s%s = alloca i32\n", ret->code, ret->name);
	asprintf(&(ret->code), "%s%s", ret->code, store_value(var_res, ret->name, INTEGER));
      }
      else
	return NULL;
    }
  }
  else if (a->t == FLOATING && b->t == FLOATING){
    ret->t = a->t;
    
     insert_previous_exp(ret, a, b);

    if(ret->code == NULL)
      asprintf(&(ret->code), "%s%s",load_value(var_a, a->name, a->t), load_value(var_b, b->name, b->t));
    else
      asprintf(&(ret->code), "%s%s%s", ret->code, load_value(var_a, a->name, a->t), load_value(var_b, b->name, b->t));
    if(made_code == 0)
      if(made_op_double(var_res, var_a, var_b, c) == NULL)
	return NULL;
      else{
	asprintf(&(ret->code), "%s%s",ret->code, made_op_double(var_res, var_a, var_b, c));
	asprintf(&(ret->code), "%s%s = alloca double\n", ret->code, ret->name);
	asprintf(&(ret->code), "%s%s", ret->code, store_value(var_res, ret->name, FLOATING));
	return ret;
      }
    else if (made_code == 1){
      if(made_comparison_double(var_res, var_a, var_b, c) != NULL){
	asprintf(&(ret->code), "%s%s",ret->code, made_comparison_double(var_res, var_a, var_b, c));
	asprintf(&(ret->code), "%s%s = alloca double\n", ret->code, ret->name);
	asprintf(&(ret->code), "%s%s", ret->code, store_value(var_res, ret->name, FLOATING));
	return ret;
      }
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

char *return_expression(enum type t, char* var, char *code){
  char *ret;
  switch(t){
  case INTEGER:
    if(code != NULL)
      asprintf(&ret,"%sret i32 %s\n", code, var);
    else
      asprintf(&ret,"ret i32 %s\n", var);
    break;
  case FLOATING:
    if(code != NULL)
      asprintf(&ret,"%sret double %s\n",code, var);
    else
      asprintf(&ret,"ret double %s\n", var);
    break;
  case VOID_T:
    if(code != NULL)
      asprintf(&ret, "%sret void\n",code);
    else
      asprintf(&ret,"ret void\n");
    break;
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
  char *ret = NULL;
  struct expression *param;
  if(e->size_param > i){
    param = look_for(e->param, i);
    switch(param->t){
    case INTEGER:
      asprintf(&ret,"i32 %s", param->val);
      break;
    case FLOATING:
      asprintf(&ret,"double %s", param->val);
      break;
    default:
      return NULL;
    }
  }
  i = 1;
  for(; i < e->size_param; i++){
    param = look_for(e->param, i);
    switch(param->t){
    case INTEGER:
      asprintf(&ret,"%s, i32 %s",ret, param->val);
      break;
    case FLOATING:
      asprintf(&ret,"%s, double %s",ret, param->val);
      break;
    default:
      return NULL;
    }    
  }
  return ret;
}

void remove_param_hash_table(struct expression *e){
  int i = 0;
  struct expression *param;
  for (; i < e->size_param ; i++){
    param = look_for(e->param, i);
    g_hash_table_remove(hash_array[level],param->name);
  }
}


char * alloca_param(struct expression *fun){
  struct expression *param;
  int i = 0;
  char *ret = NULL; 
  for (; i < fun->size_param ; ++i){
    param = look_for(fun->param, i);
    switch (param->t){
    case INTEGER:
      if (ret == NULL)
	asprintf(&ret, "%s = alloca i32\n", param->val);
      else
	asprintf(&ret, "%s%s = alloca i32\n", ret, param->val);      
      break;
      
    case FLOATING:
      if(ret == NULL)
	asprintf(&ret, "%s = alloca double\n", param->val);
      else
	asprintf(&ret, "%s%s = alloca double\n", ret, param->val);
      break;
    default:
      return NULL;
    }
  }
  return ret;
}

struct expression * double_param(char *name){
  struct expression * d = create_exp(name, new_param(name), FLOATING, 0);
  return d;
}

void insert_declaration(GHashTable * hash){
  struct expression *createCanvas = create_non_init_exp("createCanvas");
  struct llist *param = init_llist();
  add_llist(param, double_param("a"));
  add_llist(param, double_param("b"));
  init_function(createCanvas,new_func("createCanvas"), VOID_T, param);

  g_hash_table_insert(hash, func_name(createCanvas->name), createCanvas);

  struct expression *background = create_non_init_exp(new_func("background"));
  param = init_llist();
  add_llist(param, double_param("a"));
  init_function(background, new_func("background"), VOID_T, param);

  g_hash_table_insert(hash, func_name(background->name), background);
  
  struct expression *fill = create_non_init_exp(new_func("fill"));
  param = init_llist();
  add_llist(param, double_param("a"));
  init_function(fill, new_func("fill"), VOID_T, param);

  g_hash_table_insert(hash, func_name(fill->name), fill);
   
  struct expression *stroke = create_non_init_exp(new_func("stroke"));
  param = init_llist();
  add_llist(param, double_param("a"));
  init_function(stroke, new_func("stroke"), VOID_T, param);

  g_hash_table_insert(hash, func_name(stroke->name), stroke);

  struct expression *point = create_non_init_exp(new_func("point"));
  param = init_llist();
  add_llist(param, double_param("a"));
  add_llist(param, double_param("b"));
  init_function(point, new_func("point"), VOID_T, param);

  g_hash_table_insert(hash, func_name(point->name), point);
  
  struct expression *line = create_non_init_exp(new_func("line"));
  param = init_llist();
  add_llist(param, double_param("a"));
  add_llist(param, double_param("b"));
  add_llist(param, double_param("c"));
  add_llist(param, double_param("d"));
  init_function(line, new_func("line"), VOID_T, param);

  g_hash_table_insert(hash, func_name(line->name), line);

  struct expression *ellipse = create_non_init_exp(new_func("ellipse"));
  param = init_llist();
  add_llist(param, double_param("a"));
  add_llist(param, double_param("b"));
  add_llist(param, double_param("c"));
  add_llist(param, double_param("d"));
  init_function(ellipse, new_func("ellipse"), VOID_T, param);

  g_hash_table_insert(hash, func_name(ellipse->name), ellipse);

    
  struct expression *sin = create_non_init_exp(new_func("sin"));
  param = init_llist();
  add_llist(param, double_param("a"));
  init_function(sin, new_func("sin"), FLOATING, param);

  g_hash_table_insert(hash, new_func(sin->name), sin);

  struct expression *cos = create_non_init_exp(new_func("cos"));
  param = init_llist();
  add_llist(param, double_param("a"));
  init_function(cos, new_func("cos"), FLOATING, param);

  g_hash_table_insert(hash, new_func(cos->name), cos);
  
  struct expression *log10 = create_non_init_exp(new_func("log10"));
  param = init_llist();
  add_llist(param, double_param("a"));
  init_function(log10, new_func("log10"), FLOATING, param);

  g_hash_table_insert(hash, new_func(log10->name), log10);

  struct expression *sqrt = create_non_init_exp(new_func("sqrt"));
  param = init_llist();
  add_llist(param, double_param("a"));
  init_function(sqrt, new_func("sqrt"), FLOATING, param);

  g_hash_table_insert(hash, new_func(sqrt->name), sqrt);
  
}

