#include <iostream>
#include <algorithm>

char buf1[102], buf2[102], buf3[102];
int dp[101][101][101] = { 0 }, i, j, k;
int main() {
	scanf("%s %s %s", &buf1[1], &buf2[1], &buf3[1]);
	for (i = 1; buf1[i] != '\0'; i++) {
		for (j = 1; buf2[j] != '\0'; j++) {
			for (k = 1; buf3[k] != '\0'; k++) {
				if (buf1[i] == buf2[j] && buf2[j] == buf3[k]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dp[i][j][k] = std::max({
						dp[i - 1][j][k],
						dp[i][j - 1][k],
						dp[i][j][k - 1] });
				}
			}
		}
	}
	printf("%d", dp[i - 1][j - 1][k - 1]);
}

/*
두 문자열의 LCS를 구하는 방식에서 차원을 하나 추가해주었습니다.

세 문자가 같으면, 대각선 방향에서 +1한 값으로 업데이트 해줍니다.

세 문자가 다르면, 이전까지 기입된 값들 중 가장 큰 값으로 업데이트 해줍니다.
*/