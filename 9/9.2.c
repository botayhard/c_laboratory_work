#include<stdio.h>
#include<string.h>

#define SEP " \t\r\n"

int main() {
    int i=0,c,count[1024*1024+1]={0};
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w", stdout);
    while ((c = getchar()) != EOF) {
        if(!strchr(SEP,c)){
            i++;
            continue;
        }else{
            count[i]++;
            i=0;
        }
        count[i]++;
    }
    for (i = 1; i < 1024*1024+1; i++) {
        if (count[i]) printf("%d - %d\n", i, count[i]);
    }
    return 0;
}