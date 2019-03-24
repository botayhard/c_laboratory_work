#include<stdio.h>
#include<stdbool.h>
#include<iso646.h>



int main(){
    int s=0,n=0;
    char c;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(true){
        c=getchar();
        if(c<'0' or c>'9'){n=0;}
        if(c=='.'){break;}
        if(c>='0' and c<='9'){s-=n;n*=10;n+=c-'0';s+=n;}
    }
    printf("%d",s);
}