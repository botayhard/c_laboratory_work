#include <stdio.h>

void quick_sort(int a[], int l, int r){
    int i=l,j=r,x,t;
    x=a[(l+r+1)/2];
    do{
        while(a[i]<x){i++;}
        while(x<a[j]){j--;}
        if(i<=j){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
    }while(i<j);
    if(l<j){quick_sort(a,l,j);}
    if(i<r){quick_sort(a,i,r);}
}

int main()
{
    int n,a[1000000];
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",&a[i]);}
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++){printf("%d ",a[i]);}
}