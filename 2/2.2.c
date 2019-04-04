#include <stdio.h>
#include <math.h>

int
main ()
{
    long n,t,tt=0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%ld",&n);
    while(n>0){
        t=n%10;
        tt+=t;
        if(t!=0||tt!=0){printf("%d",n%10);}
        n/=10;}
}