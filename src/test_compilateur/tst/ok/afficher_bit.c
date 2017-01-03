int main() {
    /* tester l'état du bit 2 de a : */
  int a = 16 ;/* 0000 0000 0000 1111 */
  int sol;
  if (a & (1 << 2))
    {
      sol=1;
   }
  else
    {
      sol=0;
    }
  return 0;
}

