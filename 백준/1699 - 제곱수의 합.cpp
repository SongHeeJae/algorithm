#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int n, dp[100001];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
		double s = sqrt(i);
		int r = s;
		if (s == r) dp[i] = 1; // 제곱근이면 1
		else
			for (int j = 1; j <= r; j++)
				dp[i] = min(dp[i], dp[i - j*j] + 1);
	}
	printf("%d", dp[n]);
 }
 
 /*
​
예를 들어,
12 == 11 + 1 == 8 + 4 == 9 + 3입니다.
즉, 1^2 + 11 또는 2^2 + 8 또는 3^2 + 3 으로 나타낼 수 있을 때, 항의 갯수가 1개만 늘어나며 최소 항의 갯수를 구할 수 있습니다.

결국 숫자 i와 제곱 수를 반복하는 j가 있다면, 숫자 (i - j * j)에서의 최소 항의 갯수 + 1이 숫자 i에서 얻을 수 있는 최소 항의 갯수입니다.
 */