#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, a, b;
vector<int> graph[32001];
int cnt[32001] = { 0 };
priority_queue<int> pq;

int main() {
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		cnt[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (cnt[i] == 0) pq.push(-i);
	while (!pq.empty()) {
		int val = -pq.top();
		pq.pop();
		printf("%d ", val);
		for (int i = 0; i < graph[val].size(); i++) {
			if (--cnt[graph[val][i]] == 0)
				pq.push(-graph[val][i]);
		}
	}
}

/*
위상정렬을 이용하여 해결하였습니다.
먼저 각 노드가 자신에게 오는 간선의 개수를 기억해줍니다.
간선의 개수가 0이라면, 부모가 없는 고아 노드입니다.
고아 노드를 큐에 넣어줍니다.
고아 노드와 연결된 자식 노드들을 분리하면서, 연결된 자식 노드의 간선의 개수를 업데이트해줍니다.
새롭게 생긴 고아 노드를 큐에 넣어줍니다.
먼저 푸는 문제에 대한 우선순위가 없다면, 숫자가 낮은 쉬운 문제에 더 큰 우선권이 있으므로 우선순위 큐를 사용하였습니다.
*/