#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
vector<pair<pair<int, int>, int>> rotation;
int n, m, k, a[50][50], visit[6] = { 0 }, play[6], b[50][50], ans = INF;

void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = a[i][j];
		}
	}
}

void rotate(int r, int c, int s, int d) { // 회전
	if (d == s + 1) return;
	int temp = b[r - d][c - d];
	for (int i = r - d; i < r + d ; i++) // 왼쪽 당기기
		b[i][c - d] = b[i + 1][c - d];
	for (int i = c - d; i < c + d; i++) // 아래쪽 당기기
		b[r + d][i] = b[r + d][i + 1];
	for (int i = r + d; i > r - d; i--) // 오른쪽 당기기
		b[i][c + d] = b[i - 1][c + d];
	for (int i = c + d; i > c - d; i--) // 위쪽 당기기
		b[r - d][i] = b[r - d][i - 1];
	b[r - d][c - d + 1] = temp;
	rotate(r, c, s, d + 1);
}

void calArrayValue() { // 각 행의 합 계산해서 최솟값 업데이트
	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int j = 0; j < m; j++) s += b[i][j];
		ans = min(s, ans);
	}
}

void selectRotation(int d) { // 가능한 순서 조합 생성
	if (d == k) {
		copy();
		for (int i = 0; i < k; i++) {
			int idx = play[i];
			int r = rotation[idx].first.first;
			int c = rotation[idx].first.second;
			int s = rotation[idx].second;
			rotate(r, c, s, 1);
		}
		calArrayValue();
		return;
	}

	for (int i = 0; i < rotation.size(); i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		play[d] = i;
		selectRotation(d + 1);
		visit[i] = 0;
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);

	for (int i = 0; i < k; i++) {
		int r, c, s;
		scanf("%d %d %d", &r, &c, &s);
		rotation.push_back({ {r - 1, c - 1}, s });
	}

	selectRotation(0);
	printf("%d", ans);
}

/*
먼저 가능한 회전 순서의 조합을 생성해냅니다.

그 생성된 순서로 회전을 돌립니다.

그 후, 각 행의 최솟값을 찾아내줍니다.
*/