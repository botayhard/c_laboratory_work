#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef unsigned char u8;

u8* strchru8(const u8 *s,int c){
    while(*s!=(u8)c){
        if(!*s++){
            return NULL;
        }
    }
    return (u8*)s;
}


int isalphaf(u8 c) {
    return isalnum(c)||'\''==c||'`'==c||'-'==c||c>0x7F;
}

size_t count(const u8 *a,const u8 *b){
    size_t n=0,count=0;
    while(isalphaf(a[n])){++n;}
    while(*b){
        size_t i;
        while(*b&&!isalphaf(*b)){++b;}
        for(i=0;i<n&&*b&&(a[i]==toupper(*b++));++i);
        while (isalphaf(*b)) ++b;
        count+=(n==i);
    }
    return count;
}

int main(){
    FILE *f;
    char *buf,*str,*ignored;
    size_t len;
    u8 *p,*best=NULL;
    size_t n_best=0;
    if (NULL==(f=fopen("input.txt","r"))){return 1;}
    fseek(f,0,SEEK_END);
    buf=(char*)malloc(len=ftell(f)+1);
    rewind(f);
    fread(buf,1,len,f);
    (ignored=buf)[len]='\0';
    str=strchr(buf,'\n');
    *str++='\0';
    p=(u8*)str;
    while(1){
        size_t n;
        u8 *p0;
        while(*p&&!isalphaf(*p)){++p;}
        p0=p;
        for(;isalphaf(*p);++p){*p = (u8)toupper(*p);}
        if(!*p0){break;}
        if(*p){*p++='\0';}
//        printf("%s %s %d\n\n",p0,ignored,count(p0,(u8*)ignored));
        if(count(p0,(u8*)ignored)){continue;}
        n=count(p0,p)+1;
        if(n>n_best){
            n_best=n;
            best=p0;
        }
    }
    if(best){fputs((char*)best, freopen("output.txt", "w", f));}
    else{freopen("output.txt", "w", stdout);}
    free(buf);
    return 0;
}