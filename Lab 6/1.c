#include <stdio.h>

int main(){
    int n;
    printf("enter a number");
    scanf("%d",&n);
    int a[n+1];
    a[0]=0;
    a[1]=1;

    for(int i=2;i<=n;i++){
        a[i]= (a[i-1]+a[i-2]);
    }
    printf("fibonaci number %dth =%d",n,a[n]);

    return 0;
}