#include<stdio.h>
#include<math.h>

int main() {
    int n, m, p, k, l, z, i, px, kx;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    scanf("%d %d %d %d", &m, &p, &k, &l);
    z=1;
    while (m-(p-1)*l*z-(k-1)*z>z) {
        z+=1;
    }
    double q=(double)n/(z*l);
//    printf("%lf\n", q);
    px=ceil(q);
    i=n-(px-1)*l*z;
    kx=1;
    while (i>z)
    {
        kx+=1;
        i-=z;
    }
    printf("%d %d", px, kx);
}