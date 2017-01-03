int main() {
    int div=1;
    int n=12;
    int a=0;
    do {
        if(n%div==0)
	  a=div;
        div++;
    }while(div!=n+1);
}
