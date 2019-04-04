#include<stdio.h>

int prime(int n){
    if(n>2&&n%2==1){
        for(int i=3;i*i<n+1;i+=2){if (n%i==0){return 0;}}
        return 1;
    }
//   else if(n==2){return 1;}
    return 0;
}

int main(){
    int n;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d",&n);
    printf("2 ");
    for(int k=3;k<n+1;k+=2){
        if(prime(k)==1){printf("%d ",k);}
    }
}