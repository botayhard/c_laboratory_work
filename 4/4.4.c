//
// Created by botayhard on 25.02.2019.
//

#include<stdio.h>
#include <stdbool.h>
#include <iso646.h>



int main(){
    int s=0,t,chislo=0;
    char c;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(true){
        c=getchar();
        if((c<'0' or c>'9')&&chislo!=0){s+=chislo;chislo=0;}
        if(c=='.'){break;}
        if(c>='0' and c<='9'){chislo*=10;t=c-'0';chislo+=t;}
    }
    printf("%d",s);
}}