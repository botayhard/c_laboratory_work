/*There is More Than One Way To Do It*/

#include<stdio.h>

int main(){
    int n,a[250][250];
    char l[250][250],q[250];
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d",&n);
    for(int i=0;i<2*n;i++){
        for(int j=0;j<2*n;j++){scanf("%d",&a[i][j]);}
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int q1=a[i][j]*a[j][2*n-i-1];
            int q2=a[i][j]*a[2*n-i-1][2*n-j-1];
            int q3=a[i][j]*a[2*n-j-1][i];
            int q4=a[j][2*n-i-1]*a[2*n-j-1][i];
            int q5=a[j][2*n-i-1]*a[2*n-i-1][2*n-j-1];
            int q6=a[2*n-i-1][2*n-j-1]*a[2*n-j-1][i];
            if(q1+q2+q3+q4+q5+q6){printf("No");return 0;}}
    }
    for(int i=0;i<2*n;i++){
        scanf("%s",q);
        for(int j=0;j<2*n;j++){l[i][j]=q[j];}
    }
    for(int i=0;i<2*n;i++){//1
        for(int j=0;j<2*n;j++){if(a[i][j]){printf("%c",l[i][j]);}}
    }
    for(int j=0;j<2*n;j++){//2
        for(int i=2*n-1;i>=0;i--){if(a[i][j]){printf("%c",l[j][2*n-i-1]);}}
    }
    for(int i=2*n-1;i>=0;i--){//3
        for(int j=2*n-1;j>=0;j--){if(a[i][j]){printf("%c",l[2*n-i-1][2*n-j-1]);}}
    }
    for(int j=2*n-1;j>=0;j--){//4
        for(int i=0;i<2*n;i++){if(a[i][j]){printf("%c",l[2*n-j-1][i]);}}
    }
}