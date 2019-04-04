#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<iso646.h>

int main(){
    char col[7],n1,n2,ex[27],*c1,*c2;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%s",col);
    if (col[0]=='g'){
        n1='B';
        n2='Y';
    }
    if (col[0]=='o'){
        n1='R';
        n2='Y';
    }
    if (col[0]=='p'){
        n1='B';
        n2='R';
    }
    scanf("%s",ex);
    c1=strchr(ex,n1);
    c2=strchr(ex,n2);
    int f1=c1-ex+1;
    int f2=c2-ex+1;
    if(f1>f2){int t=f1;f1=f2;f2=t;}
    printf("%d %d",f1,f2);
}