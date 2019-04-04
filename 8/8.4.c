#include<stdio.h>
#include<string.h>

int liter(char lit){
    int n=0;
    if(lit>='0'&&lit<='9'){n=lit-'0';}
    else if(lit>='a'&&lit<='f'){n=lit-'a'+10;}
    return n;
}


int main(){
    int b,l;
    char s[250];
    long long r=0;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&b);
    scanf("%s",s);
    l=strlen(s);
    for(int i=0;i<l;i++){
        r*=b;
        r+=liter(s[i]);
    }
    printf("%lld",r);
}