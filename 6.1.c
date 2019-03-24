#include <stdio.h>

int main()
{
    int n,m,a[10][10],s=0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){scanf("%d",&a[i][j]);}
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1){s++;}
            else if(s!=0){printf("%d ",s);s=0;}
        }
        if(s!=0){printf("%d",s);s=0;}
        printf("\n");
    }
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(a[i][j]==1){s++;}
            else if(s!=0){printf("%d ",s);s=0;}
        }
        if(s!=0){printf("%d",s);s=0;}
        printf("\n");
    }
}