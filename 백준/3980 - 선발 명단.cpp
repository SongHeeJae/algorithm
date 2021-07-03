#include <iostream>
#include <algorithm>
using namespace std;

int c, s[11][11], ans;
bool visit[11] = { false };

void f(int idx, int sum) {
	if (idx == 11) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 11; i++) {
		if (!visit[i] && s[idx][i] > 0) {
			visit[i] = true;
			f(idx + 1, sum + s[idx][i]);
			visit[i] = false;
		}
	}
}

int main() {
	scanf("%d", &c);
	while (c--) {
		ans = 0;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				scanf("%d", &s[i][j]);
			}
		}
		f(0, 0);
		printf("%d\n", ans);
	}
}

/*
모든 포지션의 선수를 채우는, 모든 경우의 수에서의 능력치 합의 최댓값을 구해주었습니다.
*/