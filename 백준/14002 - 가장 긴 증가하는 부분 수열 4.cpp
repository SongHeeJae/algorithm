#include <cstdio>
int n, a[1000], p[1000] = { -1 }, dp[1000] = { 1 }, idx = 0, m = 1;
// dp[i]는 a[i]가 포함되는 가장 긴 증가 부분 수열의 길이
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (a[i] > a[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				p[i] = j;
			}
		}
		if (m < dp[i]) {
			m = dp[i];
			idx = i;
		}
	}
	printf("%d\n", m);
	for (int i = 0, j = idx; j != -1; j = p[j]) dp[i++] = a[j];
	while (m--) printf("%d ", dp[m]);
}

/*
dp[i]는 입력한 i번 째 수를 포함할 때의 수열의 최대 길이입니다.

i번째에서 왼쪽으로 이동하며 자신보다 작은 수를 만나면 증가하는 부분 수열이므로, 그때의 길이 + 1 로 업데이트해줬습니다.

또한, 업데이트해줄 때의 이전 위치를 기억해줬습니다. 즉, p[i]는 i번째 수 이전의 수의 위치입니다.

*/