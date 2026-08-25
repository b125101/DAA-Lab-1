#include <stdio.h>
#include <stdlib.h>
typedef struct{int l,r;} Interval;
int cmp(const void*a,const void*b){const Interval*x=a,*y=b;return x->l-y->l;}
int main(){int n;scanf("%d",&n);Interval*a=malloc(n*sizeof(Interval));for(int i=0;i<n;i++)scanf("%d %d",&a[i].l,&a[i].r);qsort(a,n,sizeof(Interval),cmp);Interval*res=malloc(n*sizeof(Interval));int m=0;for(int i=0;i<n;i++){if(m==0||a[i].l>res[m-1].r){res[m++]=a[i];}else if(a[i].r>res[m-1].r)res[m-1].r=a[i].r;}for(int i=0;i<m;i++)printf("(%d, %d)\n",res[i].l,res[i].r);free(a);free(res);return 0;}
