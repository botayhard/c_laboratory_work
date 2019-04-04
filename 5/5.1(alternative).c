//это вроде вставками, выбором двумя сабмитами ниже

#include <stdio.h>

int main()
{
    int n,a[100000],t;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",&a[i]);}
    for(int i=1;i<n;++i){
        int k=i;
        while(k>0&&a[k-1]>a[k]){
            t=a[k-1];
            a[k-1]=a[k];
            a[k]=t;
            k-=1;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
