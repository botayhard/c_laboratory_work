#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<iso646.h>

int main(){
    char l='a',temp[20];
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(true){
        int t=scanf("%s",temp);
        if(t==-1){printf("NO WINNER");return 0;}
        t=l-'a';
        if(strchr(temp,l)==0 and t%2==0){printf("PLAYER 2");return 0;}
        else if(strchr(temp,l)==0 and t%2==1){printf("PLAYER 1");return 0;}
        l++;
    }
}