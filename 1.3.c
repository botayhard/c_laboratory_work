#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    double x;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d\n", &a, &b, &c);
    int d = b * b - 4 * a * c;
    if (a == 0 && b == 0 && c == 0) {
        printf("MANY");
    } else if (a == 0 && b == 0) {
        printf("ERROR");
    } else if (a == 0) {
        x = (double) (-c) / b;
        printf("1\n%.5lf", x);
    } else if (a != 0 && b == 0 && c == 0) {
        printf("1\n%.5lf", 0);
    } else if (d == 0) {
        x = (double) (-b) / (2 * a);
        printf("1\n%.5lf", x);
    } else if (d > 0) {
        double sd = sqrt(d);
        double x1 = (-b - sd) / (2 * a);
        double x2 = (-b + sd) / (2 * a);
        if (x1 == 0) {
            x1 = sqrt(x1 * x1);
        }
        if (x2 == 0) {
            x2 = sqrt(x2 * x2);
        }
        if (a > 0) {
            printf("2\n%.5lf %.5lf", x1, x2);
        }
        if (a < 0) {
            printf("2\n%.5lf %.5lf", x2, x1);
        }
    }
    else {
        printf("NO");
    }
}