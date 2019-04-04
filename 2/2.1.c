#include<stdio.h>

double bp(double a,int n){
    if (n==0)return 1;
    if (n%2==1)return bp(a, n-1)*a;
    else{
        double b=bp(a, n/2);
        return b*b;
    }
}

int main(){
    double x,eps,res=0,xres;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%lf",&x);
    scanf("%lf",&eps);
    for(int i=1;i>0;i+=2){
        xres=bp(x,i)/i;
        if((i/2)%2==0)res+=xres;
        if((i/2)%2==1)res-=xres;
        if(xres<eps)break;
    }
    printf("%.5lf",res);
}