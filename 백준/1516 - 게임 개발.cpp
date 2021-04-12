#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 2147483647
using namespace std;

int n, a;
int cost[501];
int cnt[501] = { 0 };
vector<int> graph[501];
vector<int> d(501, 0);

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
		while (1) {
			scanf("%d", &a);
			if (a == -1) break;
			graph[a].push_back(i);
			cnt[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			q.push(i);
			d[i] = cost[i];
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i];
			d[next] = max(d[next], d[node] + cost[next]);
			if (--cnt[next] == 0) {
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", d[i]);
	}
}

/*
문제 이해를 완전히 잘못하고 있었습니다.
3
10 -1
10 -1
10 1 2 -1
처음에는, 위와 같은 테스트케이스의 답이 10 10 30이 나와야하는 줄 알았습니다.
하지만 답은 10 10 20이었습니다.
여러 개의 건물을 동시에 지을 수 있는 최소 시간을 구한다는 점을 간과하고 있던 것입니다.

위상정렬을 이용해서 선행 건물들의 시간을 먼저 구해주고,
각 건물의 선행 건물이 여러개라면, 더 오래 걸리는 선행 건물의 최소 시간으로 업데이트해주었습니다.
*/