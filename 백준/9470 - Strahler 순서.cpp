#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int t, k, m, p, a, b, node;
vector<int> graph[1001];
int indegree[1001];
int strahler[1001][2];

void init() {
	memset(indegree, 0, sizeof(indegree));
	memset(strahler, 0, sizeof(strahler));
	for (int i = 1; i <= m; i++) {
		graph[i].clear();
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &k, &m, &p);
		init();
		queue<int> q;
		while (p--) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			indegree[b]++;
		}
		for (int i = 1; i <= m; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				strahler[i][0] = 1;
			}
		}
		while (!q.empty()) {
			node = q.front();
			q.pop();
			for (int i = 0; i < graph[node].size(); i++) {
				if (strahler[node][0] == strahler[graph[node][i]][0]) {
                    // 동일한 값이 2개 이상인 경우
					strahler[graph[node][i]][1] = 1; // 2개 이상임을 표시
				}
				else if (strahler[node][0] > strahler[graph[node][i]][0]) {
                    // 최댓값 업데이트
					strahler[graph[node][i]][0] = strahler[node][0];
					strahler[graph[node][i]][1] = 0;
				}
				if (--indegree[graph[node][i]] == 0) {
					q.push(graph[node][i]);
					strahler[graph[node][i]][0] += strahler[graph[node][i]][1];
				}
			}
		}
		printf("%d %d\n", k, strahler[node][0]);
	}
}

/*
각 노드의 상위 노드 순서 최댓값이 1개인지, 2개 이상인지 기억해주었습니다.
위상정렬을 이용하여 강의 근원부터 물이 흐르는 방향을 따라 모든 노드를 방문해주었습니다.
*/