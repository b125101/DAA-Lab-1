#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){int x=*(const int*)a,y=*(const int*)b;return (x>y)-(x<y);}
int main(){int n,x;scanf("%d",&n);int*a=malloc(n*sizeof(int)),*b=malloc(n*sizeof(int));for(int i=0;i<n;i++)scanf("%d",&a[i]);for(int i=0;i<n;i++)scanf("%d",&b[i]);scanf("%d",&x);qsort(b,n,sizeof(int),cmp);int found=0;for(int i=0;i<n;i++){int l=0,r=n-1,t=x-a[i];while(l<=r){int m=l+(r-l)/2;if(b[m]==t){found=1;break;}if(b[m]<t)l=m+1;else r=m-1;}if(found){printf("Pair: %d + %d = %d\n",a[i],t,x);break;}}if(!found)printf("No such pair exists.\n");free(a);free(b);return 0;}
