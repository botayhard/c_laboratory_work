#include<stdio.h>

int main(){
    int s=0,flag=1,l;
    char c;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(flag){
        c=getchar();
        if(c=='.'){break;}
        l=(int)c-'0';
//        printf("%d\n",l);
        s+=l;
    }
//    printf("%d %d\n",l,s);
    if(s%3==0&&l%5==0){printf("YES");}
    else{printf("NO");}
}