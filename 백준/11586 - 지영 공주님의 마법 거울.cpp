#include <iostream>
#include <algorithm>
int main() {
	int n, k;
	scanf("%d", &n);
	char p[100][101];
	for (int i=0; i<n; i++) scanf("%s", p[i]);
	scanf("%d", &k);
	for (int i=0; i<n; i++) {
		if(k==2) std::reverse(p[i], p[i]+n);
		printf("%s\n", k==3 ? p[n-1-i]: p[i]);
	}
}