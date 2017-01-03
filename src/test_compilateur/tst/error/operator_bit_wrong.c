int recupererBit(int position, int nombre)
  {
    return ((1 <<< position) & nombre) >> position;
  }

int main() {
    int pos=3,n=5;
    recupererBit(pos-1,n);
}
