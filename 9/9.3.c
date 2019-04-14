#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main() {
    int count = 0;
    size_t buf_size = 1024*1024+2;
    char *buf =(char *) malloc(buf_size * sizeof(char));

    FILE *input = fopen("input.txt", "r");
    freopen("output.txt", "w", stdout);
    while(!(gets(buf))) count++;
    printf("%d",count);
    return 0;
}