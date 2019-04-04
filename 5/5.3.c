#include<stdio.h>

int gcd(int a, int b){
    return b?gcd (b,a%b):a;
}

int main(){
    int a,b;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d",&a,&b);
    printf("%d",gcd(a,b));
}