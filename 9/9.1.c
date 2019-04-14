#include<stdio.h>

int main() {
    int i, c, count[256] = {0};
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (1) {
        c = getchar();
        if (EOF == c) break;
        if (c > 12)count[c]++;
    }
    for (i = 13; i < 256; i++) {
        if (count[i]) printf("%d : %c - %d\n", i, i, count[i]);
    }
    return 0;
}