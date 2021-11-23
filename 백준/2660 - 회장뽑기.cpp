#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 51
using namespace std;

int n, a, b, visit[MAX], score[MAX];
vector<int> graph[MAX];

int bfs(int s, int v) {
	queue<int> q;
	q.push(s);
	memset(visit, 0, sizeof(visit));
	visit[s] = 1;
	
	int x;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int nxt : graph[x]) {
			if (visit[nxt]) continue;
			q.push(nxt);
			visit[nxt] = visit[x] + 1;
		}
	}
	return score[s] = visit[x] - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (1) {
		cin >> a >> b;
		if (a == -1) break;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int mn = 51, cnt = 0;
	for (int i = 1; i <= n; i++)
		mn = min(mn, bfs(i, i));

	for (int i = 1; i <= n; i++)
		if (mn == score[i]) cnt++;

	cout << mn << " " << cnt << "\n";
	for (int i = 1; i <= n; i++)
		if (mn == score[i]) cout << i << " ";
}

/*
한 노드에서 BFS를 시작했을 때, 모든 노드를 방문하게 되는 깊이가 해당 회원의 점수가 됩니다.
모든 노드마다 BFS를 수행해서 점수를 구해주었습니다.
*/