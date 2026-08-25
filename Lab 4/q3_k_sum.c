#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){int x=*(const int*)a,y=*(const int*)b;return (x>y)-(x<y);}
int search2(int*a,int l,int r,long long t){while(l<r){long long s=(long long)a[l]+a[r];if(s==t)return 1;if(s<t)l++;else r--;}return 0;}
int main(){int n,k,T;scanf("%d %d %d",&n,&k,&T);int*a=malloc(n*sizeof(int));for(int i=0;i<n;i++)scanf("%d",&a[i]);qsort(a,n,sizeof(int),cmp);int found=0; if(k==2) found=search2(a,0,n-1,T); else if(k==3){for(int i=0;i<n-2&&!found;i++){int l=i+1,r=n-1;while(l<r){long long s=(long long)a[i]+a[l]+a[r];if(s==T){found=1;break;}if(s<T)l++;else r--;}}} else {printf("This implementation supports k = 2 or 3.\n");free(a);return 0;}printf(found?"A valid combination exists.\n":"No valid combination exists.\n");free(a);return 0;}
