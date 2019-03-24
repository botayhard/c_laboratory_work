#include <stdio.h>
#include <math.h>

int
main () {
    double n, x, fractional, integer;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%lf", &n);
    x = (1 + sqrt(8 * n - 7)) / 2;
//    printf("%lf\n", x);
    fractional = modf(x, &integer);
    if (fractional==0.0){printf("%d", 1);}
    else {printf("%d", 0);}
}