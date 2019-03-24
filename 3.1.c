#include<stdio.h>

long bp(long a,long n){
    if (n==0)
        return 1;
    if (n%2==1)
        return bp(a, n-1)*a;
    else{
        long b=bp(a, n/2);
        return b*b;
    }
}

int main(){
    long n,sum,por,ls=0,n1,chislo,t2,c;
    long t=2;
    char bled;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%ld",&n);
    sum=9;
    while(sum<n){ls=sum;por=bp(10,(t-1));sum+=9*t*por;t+=1;}
    t--;
    n1=n-ls;
    chislo=(n1-1)/t+bp(10,t-1);
    t2=t-((n-ls-1)%t);
    while(t2>0){
        c=chislo%10;
        chislo/=10;
        t2-=1;
    }
    printf("%d",c);
}