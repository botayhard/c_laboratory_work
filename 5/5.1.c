#include <stdio.h>

int main()
{
    int n,a[100000],indmin,min;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",&a[i]);}
    for(int i=0;i<n;i++){
        min=1000001;
        for(int j=i;j<n;j++){
            if(a[j]<min){min=a[j];indmin=j;}
        }
        if(i!=indmin){
            a[indmin]+=a[i];
            a[i]=a[indmin]-a[i];
            a[indmin]-=a[i];
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}