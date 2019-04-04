#include <stdio.h>
#include <math.h>

int
main ()
{
    int i, a[3], b[3];
    double q, w, e, r, t, y, z, x, c, per, ph, sq;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (i = 0; i < 3; i++)
    {
        scanf("%d %d\n", &a[i], &b[i]);
    }
    q=a[0]-a[2];
    w=b[0]-b[2];
    e=a[1]-a[2];
    r=b[1]-b[2];
    t=a[0]-a[1];
    y=b[0]-b[1];

    z=sqrt(q*q+w*w);
    x=sqrt(e*e+r*r);
    c=sqrt(t*t+y*y);
//    printf("%lf %lf %lf\n", q*q+w*w, e*e+r*r, t*t+y*y);
    per=z+x+c;
    printf("%.3lf\n", per);
    ph=per/2;
    sq=sqrt(ph*(ph-z)*(ph-x)*(ph-c));
    if (sq<0) {sq*=-1;}
    printf("%.3lf\n", sq);
    return 0;
}