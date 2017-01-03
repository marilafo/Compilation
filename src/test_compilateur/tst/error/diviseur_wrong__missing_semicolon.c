int main(int argc) {
    int div=1;
    int n=3;
    n = (n/2 == 0);
    //erreur ligne suivante ? 
    int odd=(!n/2==0);
    do {
        if(n%div==0)
            div = div;
        if(!odd)
            div++;
        div++;
    }while(div<n+1)
}
