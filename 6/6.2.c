#include<stdio.h>
#include<stdbool.h>
#include<iso646.h>

int main()
{
    int n,a[250][250],t;
    char l[250][250],q;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d",&n);
    for(int i=0;i<2*n;i++){
        for(int j=0;j<2*n;j++){scanf("%d",&a[i][j]);}
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){if((a[i][j]==a[j][2*n-i-1] and a[i][j]==1) or (a[i][j]==a[2*n-i-1][2*n-j-1] and a[i][j]==1) or (a[i][j]==a[2*n-j-1][i] and a[i][j]==1) or (a[j][2*n-i-1]==a[2*n-j-1][i] and a[j][2*n-i-1]==1) or (a[j][2*n-i-1]==a[2*n-i-1][2*n-j-1] and a[j][2*n-i-1]==1) or (a[2*n-i-1][2*n-j-1]==a[2*n-j-1][i] and a[2*n-i-1][2*n-j-1]==1)){printf("No");return 0;}}
    }

    for(int i=0;i<2*n;i++){
        scanf("%c",&q);
        for(int j=0;j<2*n;j++){scanf("%c",&l[i][j]);}
    }
    q='0';
    while(true){

        for(int i=0;i<2*n;i++){
            for(int j=0;j<2*n;j++){if(a[i][j]){printf("%c",l[i][j]);}}
        }
        if((++q)=='4'){break;}
        for(int i=0;i<n;i++){
            for(int j=i;j<2*n-1-i;j++){
                t=a[i][j];
                a[i][j]=a[2*n-j-1][i];
                a[2*n-j-1][i]=a[2*n-i-1][2*n-j-1];
                a[2*n-i-1][2*n-j-1]=a[j][2*n-i-1];
                a[j][2*n-i-1]=t;
            }
        }
    }
}