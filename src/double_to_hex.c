#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

char *double_to_hex_str(double d){
  char *s = NULL;
  union{
    double a;
    long long int b;
  } u;
  if(d == 0.0){
    asprintf(&s,"0x0000000000000000");
    return s;
  }
  u.a = d;
  asprintf(&s, "%#08llx", u.b);
  return s;
}
