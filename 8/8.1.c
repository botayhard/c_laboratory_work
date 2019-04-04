#include<stdio.h>
#include<stddef.h>
#include<limits.h>

int main(){
    long long n,max=0,c=0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%lld",&n);
    for(int i=CHAR_BIT*sizeof(int)-1;i>-1;i--){
        if(n&(1<<i)){c++;}
        else{c=0;}
        if(c>max){max=c;}
    }
    printf("%lld",max);
}