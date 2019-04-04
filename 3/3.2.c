#include <stdio.h>
int prime[1000001] = {0};
int main(){
    int n;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d",&n);
    for(int i = 2; i*i<n; ++i)
        if (prime[i]==0)
            for(int k=i*i;k<n+1;k+=i)
                prime[k]=1;
    for(int i=2;i<n+1; ++i)
        if (prime[i]==0)
            printf("%d ",i);
}