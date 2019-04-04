#include <stdio.h>

int main()
{
    int flag=0;
    char l='\0',ll='\0',c;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(!flag){
        c=getchar();
        if(c=='.'){break;}
        ll=l;
        l=c;
        if(ll!='\0'){putchar(ll);}
    }
    if(l=='e'){putchar(l);putchar('r');}
    else if(ll!='e'||l!='r'){putchar(l);printf("er");}
    else{printf("st");}
}