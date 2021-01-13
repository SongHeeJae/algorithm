#include <cstdio>
int main(){int a[26]={0},i=1,c;for(;(c=getchar()-97)!=-87;i++)a[c]?1:a[c]=i;for(int b:a)printf("%d ",--b);}