#include <cstdio>
int main() {
	int n;
	scanf("%d", &n);
	n-=1000;
	printf("%d",-(n/500+(n%500)/100+(n%100)/50+(n%50)/10+(n%10)/5+n%5));
}
