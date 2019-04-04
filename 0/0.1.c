#include <stdio.h>

int main ()
{
    int a, b;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d", a+b);
}