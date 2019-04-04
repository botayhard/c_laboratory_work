#include<stdio.h>

int gcd(int a, int b){
    return b?gcd(b,a%b):a;
}

unsigned long long lcm(int a, int b){
    return (unsigned long long)a/gcd(a,b)*b;
}

int main(){
    int n,a,b;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        printf("%llu\n", lcm(a,b));
    }
}