#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SEP " \t\r\n.,!@#$%^&*№:?-_+=;()[]{}/|\<>\"~"

int mycmp(const char **a, const char **b ) {//так не стабильно сортирует (адреса идут вразнобой)
    return strcmp(*a,*b);
}


int mycmpmk2(const void * a, const void * b ) {
    const char *pa = *(const char**)a;
    const char *pb = *(const char**)b;
    int r0 = strcmp(pa, pb);
    int r = (pa > pb) - (pa < pb);
    return r0 ? r0 : r;
}

int main() {
    FILE *f;
    char *buf, *ignored, *p;
    size_t len;
    char **tokens;
    char *best = NULL;
    size_t n_tokens = 0, n_best = 0;
    size_t i, n;

    if (NULL == (f = fopen("input.txt", "r")))
        return 1;

    fseek(f, 0, SEEK_END);
    buf = (char *) malloc(len = ftell(f) + 1);
    rewind(f);
    fread(buf, 1, len, f);
    ignored = strchr(buf, '\n');
    buf[len] = '\0';
    for (p = buf; *p; ++p) *p = toupper(*p);
    tokens = (char **)malloc(sizeof(char *) / 2 * len);
    for (p = strtok(buf, SEP); NULL != p; tokens[n_tokens] = p, p = strtok(NULL, SEP)) n_tokens++;

//    for(int j=0;j<n_tokens;j++){printf("%s %d\n",tokens[j],tokens[j]);}
    qsort(tokens, n_tokens, sizeof(char *), mycmpmk2);//устойчивая лексикографическая сортировка адресов токенов
//    for(int j=0;j<n_tokens;j++){printf("%s %d\n",tokens[j],tokens[j]);}

    for (p = tokens[i = n = 0]; i < n_tokens; ++i) {
        if (strcmp(tokens[i], p) == 0) {
            ++n;
            continue;
        }

        if (n > n_best && p > ignored) {
            n_best = n;
            best = p;
        }

        p = tokens[i];
        n = 1;
    }

    if (best) {
        fputs(best, freopen("output.txt", "w", f));
    } else {
        freopen("output.txt", "w", stdout);
    }

    fclose(f);
    free(tokens);
    free(buf);
    return 0;
}
