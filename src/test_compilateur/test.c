#include <stdlib.h>
#include <stdio.h>


union type{
  int i; 
  float f;
};


int main (int argc, char **argv){
  union type toto[]={1,0.1,2,"la"};

  return 1;
} 
