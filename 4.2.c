#include <stdio.h>

int
main ()
{
    int l=0,flag=1,anotherflag=0;
    char c;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(flag){
        c=getchar();
        if(c=='.'){break;}
        l+=1;
        if(l==2&&c=='A'){anotherflag=1;}
    }
    if(l==3&&anotherflag){printf("FITS");}
    else{printf("DOES NOT FIT");}
}