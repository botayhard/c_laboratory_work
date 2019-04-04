#include<stdio.h>
#include<stddef.h>
#include<limits.h>

int main(){
    long t,n;
    long long r=0;
    unsigned long long pow=1;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%ld",&n);
    for(int i=CHAR_BIT*sizeof(int)-1;i>-1;i--){
        if(n&(1<<i)){t=1;}
        else{t=0;}
        printf("%d",t?1:0);
        r+=t*pow;
        pow*=2;
    }
    t=(int)r;
    printf("\n%ld\n",t);
    for(int i=CHAR_BIT*sizeof(int)-1; i>-1;i--){
        printf("%d",t&(1<<i)?1:0);
    }
}