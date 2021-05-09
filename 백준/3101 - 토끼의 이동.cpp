#include <cstdio>

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int n, k, x = 1, y = 1, alp['Z'];
long long ans = 1;
char jump[300001], d[] = "DRUL";

inline long long getValue() {
	long long idx = x + y - 1;
	long long oidx = idx > n ? idx - n : 0;
	if (idx % 2) return idx * (idx + 1) / 2 - x + 1 - oidx * oidx;
	else return idx * (idx - 1) / 2 + x - oidx * oidx;
}

int main() {
	scanf("%d %d %s", &n, &k, jump);
	for (int i = 0; i < 4; i++) alp[d[i]] = i;
	for (int i = 0; i < k; i++) {
		x += dx[alp[jump[i]]];
		y += dy[alp[jump[i]]];
		ans += getValue();
	}
	printf("%lld", ans);
}

/*
각 대각선마다 번호(1번부터 시작)를 붙여줍니다.
대각선의 번호를 이용해서 해당하는 좌표에 적혀진 값을 구할 수 있습니다.
대각선의 번호 idx는 x + y - 1로 구할 수 있습니다.
idx가 짝수라면, 좌표의 값은 idx * (idx - 1) / 2 + x 입니다.
idx가 홀수라면, 좌표의 값은 idx * (idx + 1) / 2 - x + 1 입니다.
하지만 대각선의 번호가 N을 초과하면 추가적인 계산이 필요합니다.
대각선의 번호가 x만큼 넘어간다면, 계산된 좌표 값에 x * x 를 빼주어야합니다.
시작 지점의 좌표를 (1, 1)로 보고 토끼가 이동할 때마다 각 좌표의 계산된 값을 더해주었습니다. 
*/