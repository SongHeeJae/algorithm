#include <cstdio>
int main() {int n;scanf("%d",&n);n%=8;printf("%d",n>5||n==0?(18-n)%8:n);}