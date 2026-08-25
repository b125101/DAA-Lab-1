#include <stdio.h>
#include <stdlib.h>
typedef struct{int time,type;} Event;
int cmp(const void*a,const void*b){const Event*x=a,*y=b;return x->time-y->time;}
int main(){int n;scanf("%d",&n);Event*e=malloc(2*n*sizeof(Event));for(int i=0;i<n;i++){int a,b;scanf("%d %d",&a,&b);e[2*i]=(Event){a,1};e[2*i+1]=(Event){b,-1};}qsort(e,2*n,sizeof(Event),cmp);int cur=0,mx=0,t=0;for(int i=0;i<2*n;i++){cur+=e[i].type;if(cur>mx){mx=cur;t=e[i].time;}}printf("Maximum people: %d\nTime: %d\n",mx,t);free(e);return 0;}
