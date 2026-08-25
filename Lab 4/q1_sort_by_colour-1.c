#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int number; char colour; } Item;
int rankColour(char c){ return c=='R'?0:(c=='B'?1:2); }
int main(){ int n; scanf("%d",&n); Item *a=malloc(n*sizeof(Item)), *out=malloc(n*sizeof(Item)); int cnt[3]={0};
 for(int i=0;i<n;i++){ scanf("%d %c",&a[i].number,&a[i].colour); cnt[rankColour(a[i].colour)]++; }
 int pos[3]={0,cnt[0],cnt[0]+cnt[1]}; for(int i=0;i<n;i++) out[pos[rankColour(a[i].colour)]++]=a[i];
 for(int i=0;i<n;i++) printf("%d %c\n",out[i].number,out[i].colour); free(a);free(out); return 0; }
