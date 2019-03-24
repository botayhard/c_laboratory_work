#include<stdio.h>
int a[1000000];

int main(){
    int n,x,l,r;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d",&n,&x);
    l=0;
    r=n-1;
    for(int i=0;i<n;i++){scanf("%d",&a[i]);}
    int qwerty=1;
    while(qwerty!=0){
//      printf("%d %d %d\n",l,r,l+(r-l)/2);
        if(a[l+(r-l)/2]==x){break;}
        if(n==0){l=-1;r=-1;break;}
        (x>a[l+(r-l)/2]) ? (l+=n/2) : (r-=n/2);
        n/=2;
    }
    printf("%d", l+(r-l)/2);
}