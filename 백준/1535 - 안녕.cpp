#include <iostream>
#include <algorithm>
#define MAX 20
using namespace std;

int n, a[MAX], b[MAX], dp[100] = { 0 };
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 99; j >= a[i]; j--) {
			dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
		}
	}
	printf("%d", dp[99]);
}

/*
배낭 문제와 동일한 풀이였습니다.
체력은 100이지만 0이 되면 죽으므로, 99라고 잡아주었습니다.
*/