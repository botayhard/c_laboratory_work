#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(){
    int ch=0;
    char fir[255],cur[255];
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%s",fir);
    while(true){
        int t=scanf("%s",cur);
        if(t==-1){return 0;}
        for(int i=0;i<strlen(fir);i++){if(strchr(cur,fir[i])!=0){ch++;}}
        if(ch==0){printf("%s\n",cur);}
        ch=0;
    }
}