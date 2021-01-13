#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t, n, m, a, b, c;

int din[1001][1001]; // a, b 다리 사이에 필요한 다이너마이트 개수
bool visit[1001] = { false, };
vector<vector<int>> bridge; // 다리 연결 그래프

int dfs(int node, int res) {
	visit[node] = true;
	int c = 0;
	for (int i = 0; i < bridge[node].size(); i++) {
		int nextNode = bridge[node][i];
		if (visit[nextNode]) continue;
		c += dfs(nextNode, din[node][nextNode]);
	}
	visit[node] = false;
	if (c) return min(res, c); // 최소로 유지
	else return res; // 더 이상 자식 노드가 없으면 다이너마이트 개수 그대로 반환 
}
int main() {
	scanf("%d", &t);
	while (t--) {
		bridge.clear();
		scanf("%d %d", &n, &m);
		bridge.resize(n+1);
		while (m--) {
			scanf("%d %d %d", &a, &b, &c);
			bridge[a].push_back(b);
			bridge[b].push_back(a);
			din[a][b] = din[b][a] = c;
		}
		int ans = dfs(1, 987654321);
		printf("%d\n", ans == 987654321 ? 0 : ans); // 섬이 하나일 경우 0
	}
}

/*

dfs를 변형하여 풀었습니다. 두 섬을 연결하는 다리를 최소한의 개수로 만들었다고 합니다. 트리 구조인듯 합니다.

하위트리에서 올라오면서 다이너마이트가 필요한 갯수를 최솟값으로 유지해주었습니다.
*/