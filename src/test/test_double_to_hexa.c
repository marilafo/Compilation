#include "double_to_hex.c"

int main (){
  double a = 0.0;
  double b = 0.1;
  double c = 3.3;

  printf("a: %s\n", double_to_hex_str(a));
  printf("b: %s\n", double_to_hex_str(b));
  printf("c: %s\n", double_to_hex_str(c));

  return 1;
}
