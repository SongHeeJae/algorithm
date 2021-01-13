#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;
bool visited[100001] = { false, };
int d[] = { -1, 1, 0 };
int p[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	while (!q.empty()) {
		int x = q.front().first;
		int t = q.front().second;
		q.pop();

		if (x == k) {
			printf("%d\n", t);
			int i = k;
			vector<int> path;
			for (; i != n; i = p[i]) path.push_back(i);
			printf("%d ", n);
			for (int i = path.size() - 1; i >= 0; i--) printf("%d ", path[i]);
			break;
		}

		d[2] = x;
		for (int i = 0; i < 3; i++) {
			int nx = x + d[i];
			if (nx < 0 || nx >= 100001 || visited[nx]) continue;
			p[nx] = x;
			visited[nx] = true;
			q.push({ nx, t + 1 });
		}
	}
}
