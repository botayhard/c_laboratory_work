#include<stdio.h>

char liter(int n){
    char lit;
    if(n<10){lit='0'+n;}
    else{lit='a'+n-10;}
    return lit;
}

int main(){
    long long n,b,t=1,i=0;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%lld",&b);
    scanf("%lld",&n);
    if(n<2){printf("%d",n);return 0;}
    while(t<n){i++;t*=b;}
    i--;
    t/=b;
    for(int j=i;j>-1;j--){
        for(int k=b-1;b>0;k--){
            if(t*k-n>0){continue;}
            printf("%c",liter(k));
            n-=t*k;
            t/=b;
            break;
        }
    }
}