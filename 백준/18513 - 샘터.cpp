#include <iostream>
#include <queue>
#define W 100100000
using namespace std;

int dx[] = { -1,1 };

queue<pair<int, int>> q; // {좌표, 거리}
int n, k, a;
long long ans = 0;
bool visit[200200001] = {false};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		q.push({ a, 0 });
		visit[a + W] = true;
	}
	
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int d = q.front().second;
		q.pop();

		ans += d;

		if (++cnt == n + k) {
			break;
		}

		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			if (visit[nx + W]) continue;
			q.push({ nx, d + 1 });
			visit[nx + W] = true;
		}
	}
	cout << ans;
}

/*
샘터의 위치를 큐에 담아두고, 그 지점에서부터 BFS를 수행하며 지어지는 집들의 거리를 더해주었습니다.
주의해야할 점은, 주어진 샘터의 위치 조건은 집의 위치 조건과는 무관했습니다.
*/