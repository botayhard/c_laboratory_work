#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

#define SEP " \t\r\n.,!@#$%^&*№:?-_+=;()[]{}/|\\<>\"~"

int mycmp(const void *a, const void *b) {
    const char *pa = *(const char **) a;
    const char *pb = *(const char **) b;
    return strcmp(pa, pb);
}

int isalphaf(char c) {
    return isalnum(c) || '\'' == c || '`' == c || '-' == c;
}

void del(char *src, const char *del, size_t pos) {
    size_t wrdlen = strlen(del);
    size_t srclen = strlen(src);
    if (pos + wrdlen + 1 <= srclen) {
        for (size_t i = pos;; i++) {
            src[i] = src[i + wrdlen + 1];
            if (src[i] == '\0') break;
        }
    } else src[pos] = '\0';
}

int isword(const char *str, int begin, int end) {
    int tr1 = 1, tr2 = 1, lenstr = strlen(str);
    if (begin != 0) tr1 -= isalphaf(str[begin - 1]);
    if (end != lenstr) tr2 -= isalphaf(str[end + 1]);
    return tr1 * tr2;
}

int strkmp(const char *src, const char *sub, int s) {
    int srclen = strlen(src);
    int sublen = strlen(sub);
    int *pref = (int *) malloc(sublen * sizeof(int));
    pref[0] = 0;
    for (int i = 1, j = 0; i < sublen; i++) {
        while (j > 0 && sub[j] != sub[i]) j = pref[j - 1];
        if (src[j] == src[i]) j++;
        pref[i] = j;
    }
    for (int i = 0, j = 0; i < srclen; i++) {
        while (j > 0 && sub[j] != src[i]) j = pref[j - 1];
        if (sub[j] == src[i]) j++;
        if (j == sublen) {
            if (isword(src, i - j + 1, i)) {
                free(pref);
                return s + i - j + 1;
            } else {
                free(pref);
                return strkmp(src + (i + (sublen == 1)), sub, s + i);
            }
        }
    }
    free(pref);
    return -1;
}

void clean(char *src, const char *wst) {
    int cerf = strkmp(src, wst, 0);
    if (cerf >= 0) {
        del(src, wst, cerf);
        clean(src + cerf, wst);
    }
}

int main() {
    FILE *f;
    char *buf, *str, *ign;
    char **tokens;
    size_t len;
    size_t n_tokens = 0, n_best = 0;
    size_t i, n;
    char *p, *best = NULL;
    if (NULL == (f = fopen("input.txt", "r"))) return 1;
    fseek(f, 0, SEEK_END);
    buf = (char *) malloc(len = ftell(f) + 1);
    rewind(f);
    fread(buf, 1, len, f);
    (ign = buf)[len] = '\0';
    str = strchr(buf, '\n');
    *str++ = '\0';
    p = str;
    int it = 0;
    for (; *ign; ++ign) {
        *ign = toupper(*ign);
        it++;
    }
    ign -= it;
    for (; *p; ++p) *p = toupper(*p);
    p = str;
    char del[] = " ";
    for (char *tokbuf = strtok(ign, del); tokbuf; tokbuf = strtok(NULL, del)) clean(p, tokbuf);
    printf(p);
    tokens = (char **) malloc(sizeof(char *) / 2 * len);
    for (p = strtok(p, SEP); NULL != p; tokens[n_tokens++] = p, p = strtok(NULL, SEP));

    qsort(tokens, n_tokens, sizeof(char *), mycmp);

    for (p = tokens[i = n = 0]; i < n_tokens; ++i) {
        if (strcmp(tokens[i], p) == 0) {
            ++n;
            continue;
        }
        if (n > n_best) {
            n_best = n;
            best = p;
        }
        p = tokens[i];
        n = 1;
    }

    if (best) fputs(best, freopen("output.txt", "w", f));
    else freopen("output.txt", "w", stdout);

    fclose(f);
    free(tokens);
    free(buf);
//    printf("runtime=%f", clock() / 1000.0);
    return 0;
}
