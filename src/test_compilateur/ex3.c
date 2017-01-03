int main() {
  int i,x;	
  x = 0;
  do {
    x += i;
    ++i;
    i++;
  }
  while (x<1000);
  return x;
}
