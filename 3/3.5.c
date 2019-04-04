#include <stdio.h>
int a[10001];

int main()
{
    int n,s,t,r=0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d",&n,&s);
    for(int q=0;q<n;q++){
        scanf("%d",&a[q]);
    }
    for(int i=0;i<n;i++){
        t=0;
        for(int j=i;j<n;j++){
            t+=a[j];
            if(t==s){r+=1;continue;}
            if(t>s){continue;}
        }
    }
    printf("%d",r);
}