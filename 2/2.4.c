#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    long n,rn;
    double t,rr=1.0,rt;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%ld",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&t);
        rt=t-ceil(t);
//        printf("%f\n",rt);
        if(rt<0){rt*=-1;}//abs(integer, not double)
        if(rt<rr){
//            printf("%f",t);
            rr=rt;
            rn=i+1;
        }
    }
    printf("%ld",rn);
}