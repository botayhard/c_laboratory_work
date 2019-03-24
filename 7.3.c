#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<iso646.h>

int main(){
    int t=0;
    char s1[27],s2[27],r[27];
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%s %s",s1,s2);
    for(int i=0;i<strlen(s1);i++){
        if(strchr(s2,s1[i])==0){r[t]=s1[i];r[t+1]='\0';t++;}
    }
    if(t==0){printf("Empty Set");return 0;}
    for(int i=0;i<strlen(r)-1;i++){
        for(int j=i+1;j<strlen(r);j++){
            if(r[i]>r[j]){char t=r[i];r[i]=r[j];r[j]=t;}
        }
    }
    printf("%s",r);
}