#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define INF 2147483647
using namespace std;

int t, n, arr[501], m, a, b, indegree[501];
bool chk[501][501];
vector<int> graph[501], res;

int main() {
	scanf("%d", &t);
	while (t--) {
		queue<int> q;
		memset(chk, false, sizeof(chk));
		memset(indegree, 0, sizeof(indegree));
		res.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            graph[i].clear();   
        }
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			chk[a][b] = chk[b][a] = true;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int node = chk[arr[i]][arr[j]] ? arr[j] : arr[i];
				int next = chk[arr[i]][arr[j]] ? arr[i] : arr[j];
				graph[node].push_back(next);
				indegree[next]++;
			}
		}

		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			res.push_back(node);
			for (int i = 0; i < graph[node].size(); i++) {
				if (--indegree[graph[node][i]] == 0) q.push(graph[node][i]);
			}
		}

		if (res.size() == n) {
			for (int i = 0; i < res.size(); i++) {
				printf("%d ", res[i]);
			}
		}
		else {
			printf("IMPOSSIBLE");
		}
		printf("\n");
	}
}

/*
작년 순위가 4->3->2->1이라면,
4->3, 4->2, 4->1,
3->2, 3->1
2->1 처럼 모든 간선을 만들어줍니다.
만약 상대적인 순위가 뒤바뀐 팀이라면, 두 팀의 간선을 뒤집어줍니다.

이렇게 구한 간선으로 그래프 형태를 만든 뒤, 위상정렬을 통해 순위를 구해줍니다.
*/