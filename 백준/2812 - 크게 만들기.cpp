#include <iostream>
int n, k, idx=0;
char c, num[500001];
int main() {
	for (scanf("%d %d", &n, &k); n-- && scanf(" %c", &c);) {
		while (idx && num[idx - 1] < c && k-- > 0) idx--;
		num[idx++] = c;
		if (k <= 0) break;
	}
	num[idx - (k < 0 ? 0 : k)] = '\0';
	printf("%s", num);
	while(n-->0) printf("%c", getchar());
}