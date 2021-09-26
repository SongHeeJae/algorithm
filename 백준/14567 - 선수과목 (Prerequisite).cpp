#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001

int n, m, a, b;
vector<int> graph[MAX];
int depth[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		graph[a].push_back(b);
	}
	
	for (int i = 1; i <= n; i++) {
		depth[i] = max(depth[i], 1);
		for (auto nxt : graph[i]) {
			depth[nxt] = max(depth[nxt], depth[i] + 1);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << depth[i] << " ";
	}
}

/*
노드의 깊이를 더 큰 값으로 업데이트하는 방식으로 풀 수 있었습니다.


다음 풀이는 위상정렬을 이용하였습니다.
진입 차수가 0인 시작 지점의 노드들을 1로 초기화하고,
다음 순서로 큐로 들어가는 노드들의 깊이는 +1을 해주었습니다.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1001

int n, m, a, b;
vector<int> graph[MAX];
int indegree[MAX] = { 0 };
int depth[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			depth[i] = 1;
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto nxt : graph[node]) {
			if (--indegree[nxt] == 0) {
				q.push(nxt);
				depth[nxt] = depth[node] + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << depth[i] << " ";
	}
}
*/