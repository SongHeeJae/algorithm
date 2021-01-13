#include <iostream>
#include <queue>
using namespace std;

int n, k, x, t;
bool visited[100001] = { false, };
int d[] = { 0,-1,1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	queue<pair<int, int>> q;
	visited[n] = true;
	q.push({ 0, n });
	while (!q.empty()) {
		t = q.front().first;
		x = q.front().second;
		q.pop();
		if (x == k) break;
		d[0] = x;
		for (int i = 0; i < 3; i++) {
			int nx = x + d[i];
			if (nx < 0 || nx > 100000 || visited[nx]) continue;
			visited[nx] = true;
			if (i == 0) {
				for (int i = nx; i < 100001; i *= 2) {
					q.push({ t, nx });
					visited[nx] = true;
				}
			}
			else q.push( { t + 1, nx });
		}
	}
	cout << t;
}
