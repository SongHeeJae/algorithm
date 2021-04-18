#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, k, ans = -1, num[10];
bool visit[1000001][11] = { false };
queue<pair<int, int>> q;

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

int generateNumber(int len) {
	if (num[len - 1] == 0) return -1;
	int res = 0;
	for (int i = len - 1; i >= 0; i--)
		res = res * 10 + num[i];
	return res;
}

int main() {
	scanf("%d %d", &n, &k);
	q.push({n, 0});
	while (!q.empty()) {
		int x = q.front().first;
		int c = q.front().second;
		if (c == k) break;
		q.pop();
		int len = 0;
		while (x != 0)
			num[len++] = x % 10, x /= 10;
		for (int i = len - 1; i >= 0; i--) {
			for (int j = i - 1; j >= 0; j--) {
				swap(num[i], num[j]);
				int res = generateNumber(len);
				swap(num[i], num[j]);
				if (res == -1) continue;
				if (visit[res][c]) continue;
				visit[res][c] = true;
				q.push({ res, c + 1 });
			}
		}
	}
	while (!q.empty()) {
		ans = max(ans, q.front().first);
		q.pop();
	}
	printf("%d", ans);
}

/*
큐를 이용하여 풀었습니다.

각 위치의 숫자를 바꾼 값들을 큐에 넣고, 그 값들로 숫자의 위치를 바꾼 값들을 새로 만들어주었습니다.

연산이 k번 수행되었다면, 그 때 큐에 축적된 값들의 최댓값을 구해주었습니다.
*/