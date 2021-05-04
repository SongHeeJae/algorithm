#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int t, a, b;

bool primes[10000] = { false };
bool visit[10000] = { false };

void initPrimes() {
	for (int i = 2; i <= 9999; i++) {
		if (primes[i]) continue;
		for (int j = i + i; j <= 9999; j += i) {
			primes[j] = true;
		}
	}
}

int bfs(int start, int end) {
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	visit[start] = true;
	q.push({ start, 0 });
	while (!q.empty()) {
		int x = q.front().first;
		int c = q.front().second;
		q.pop();
		if (x == end) return c;
		for (int i = 1; i < 10000; i *= 10) {
			int temp = x;
			for (int j = 0; j < 9; j++) {
				temp += i;
				if ((temp / i) % 10 == 0) temp -= i * 10; // 자릿수 넘어가면 복구
				if (primes[temp] || temp < 1000 || visit[temp]) continue;
				visit[temp] = true;
				q.push({ temp, c + 1 });
			}
		}
	}
	return -1;
}

int main() {
	initPrimes();
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		int res = bfs(a, b);
		if (res == -1) printf("Impossible\n");
		else printf("%d\n", res);
	}
}

/*
먼저 네 자리 소수 값들을 미리 초기화 해둡니다.
그리고 시작점 소수의 각 자릿수들을 변환하며, 그 값이 소수라면 BFS를 진행해줍니다.
*/