#include <stdio.h>
#include <stdlib.h>
typedef struct{int x,delta;} Event;
int cmp(const void*a,const void*b){const Event*x=a,*y=b;if(x->x!=y->x)return x->x-y->x;return y->delta-x->delta;}
int main(){int n;scanf("%d",&n);Event*e=malloc(2*n*sizeof(Event));for(int i=0;i<n;i++){int l,r;scanf("%d %d",&l,&r);e[2*i]=(Event){l,1};e[2*i+1]=(Event){r,-1};}qsort(e,2*n,sizeof(Event),cmp);int cur=0,mx=0,p=0;for(int i=0;i<2*n;i++){cur+=e[i].delta;if(cur>mx){mx=cur;p=e[i].x;}}printf("Point: %d\nMaximum overlapping intervals: %d\n",p,mx);free(e);return 0;}
