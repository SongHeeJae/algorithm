#include <cstdio>

int n, p[2][48], s[48], ans = 0, origin[48];

bool chk(int cur) {
	for (int i = 0; i < n; i++)
		if (p[cur][i] != i % 3) return false;
	return true;
}

void shuffle(int cur, int next) {
	for (int i = 0; i < n; i++) {
		p[next][s[i]] = p[cur][i];
	}
}

bool cycle(int cur) {
	for (int i = 0; i < n; i++)
		if (origin[i] != p[cur][i]) return false;
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[0][i]);
		origin[i] = p[0][i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	while (1) {
		int cur = ans % 2;
		int next = (ans + 1) % 2;
		if (chk(cur)) break;
		shuffle(cur, next);
		if (cycle(next)) {
			ans = -1;
			break;
		}
		ans++;
	}
	printf("%d", ans);
}

/*
P 배열이 [2, 0, 1] 이라면,
0번 카드는 2번한테 주고, 1번 카드는 0번에게 주고, 2번 카드는 1번에게 주면 됩니다. 
즉, 주어진 P 배열을 [0, 1, 2, 0, 1, 2, ...] 형태로 만들어주면 됩니다.
P 배열의 변화 과정에서 사이클이 발생할 시, 위 형태로 만들어줄 수 없습니다.
초기의 P 배열이 중복되어서 나타나면 -1을 출력하고 종료합니다. 
*/