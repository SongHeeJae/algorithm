#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int t, n, k, w, a, b, d[1001], indegree[1001], time[1001];

vector<int> graph[1001];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &d[i]);
			time[i] = indegree[i] = 0;
			graph[i].clear();
		}
		while (k--) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			indegree[b]++;
		}
		scanf("%d", &w);

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				time[i] = d[i];
			}
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			if (node == w) break;
			for (int i = 0; i < graph[node].size(); i++) {
				int next = graph[node][i];
				time[next] = max(time[next], time[node] + d[next]);
				if (--indegree[next] == 0) {
					q.push(next);
				}
			}
		}
		printf("%d\n", time[w]);
	}
}

/*
각 건물을 지을 때까지 걸리는 소요 시간 = 선행 건물을 지을 때까지 걸리는 소요 시간 + 해당 건물을 짓는데 걸리는 소요 시간입니다.
위상정렬을 통해 순서대로 방문하면서 소요 시간을 업데이트해주었습니다.
*/