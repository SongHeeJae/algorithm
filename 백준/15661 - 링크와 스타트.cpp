#include <cstdio>
#include <cmath>
int n, s[20][20], ans = 1e9, t[2][20], c[2], v[2], i, j, k;
int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n && scanf("%d", &s[i][j]); j++);
	for (i = 1; i < (1 << (n - 1)); i++) {
		c[0] = c[1] = v[0] = v[1] = 0;
		for (j = 0; j < n; j++) (i & (1 << j)) > 0 ? t[0][c[0]++] = j : t[1][c[1]++] = j;
		for (j = 0; j < c[0]; j++)
			for (k = j + 1; k < c[0]; k++) v[0] += s[t[0][j]][t[0][k]] + s[t[0][k]][t[0][j]];
		for (j = 0; j < c[1]; j++)
			for (k = j + 1; k < c[1]; k++) v[1] += s[t[1][j]][t[1][k]] + s[t[1][k]][t[1][j]];
		if ((k = abs(v[0]-v[1])) < ans) ans = k;
	}
	printf("%d", ans);
}

/*

비트 연산을 이용해서 풀었습니다.
나올 수 있는 팀의 경우의 수는 2^(n-1) - 1개 입니다. 공집합인 팀은 없고, 팀은 서로 뒤집을 수 있기 때문입니다.

예를 들어, n==4라면,

[1] - [2, 3, 4] (비트로 보면 0001)
[2] - [1, 3, 4] (비트로 보면 0010)
[1, 2] - [3, 4] (비트로 보면 0011)
[3] - [1, 2, 4] (비트로 보면 0100)
[1, 3] - [2, 4] (비트로 보면 0101)
[2, 3] - [1, 4] (비트로 보면 0110)
[1,2,3] - [4] (비트로 보면 0111)

형태와 같은 7개의 팀을 만들어낼 수 있습니다.

각 팀원에 대해 구분해낸 뒤, 각 팀의 합을 구하여 능력치의 차이를 계산해주었습니다.
*/