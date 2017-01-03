int main(int argc,char **argv)
{
  int a=atoi(argv[1]);
  int count=0;
  while((a!=1)&&(a>0)) {
    printf("%d ",a);
    if(a%2==0)
      a/=2;
    else {
      a*=3;
      a+=1;
    }
    count++;
  }
  printf("%d\nnombre d'étapes : %d\n",a,++count);
}
