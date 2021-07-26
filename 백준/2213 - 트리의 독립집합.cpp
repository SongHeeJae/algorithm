#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// dp[i][0] = 집합 i ~ N번에서 i번 노드가 선택되었을 때 최대 독립 집합 크기, initial value = w[i]
// dp[i][1] = 집합 i ~ N번에서 i번 노드가 선택되지 않았을 때 최대 독립 집합 크기, initial value = 0
int dp[10001][2];
int n, a, b;
vector<int> graph[10001];
vector<int> ans;

void init(int node, int prev) {
	for (int next : graph[node]) {
		if (next == prev) continue;
		init(next, node);
		dp[node][0] += dp[next][1]; // 현재 노드 선택 O, 다음 노드 선택 X
		dp[node][1] += max(dp[next][0], dp[next][1]); // 현재 노드 선택 O, 다음 노드 선택 O or X
	}
}

void findSet(int node, bool isIncluded, int prev) {
	if (isIncluded) ans.push_back(node);
	for (int next : graph[node]) {
		if (next == prev) continue;
		bool nextIncluded = false;
		if (!isIncluded) nextIncluded = dp[next][0] > dp[next][1];
		findSet(next, nextIncluded, node);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i][0];
		dp[i][1] = 0;
	}

	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	init(1, -1);
	findSet(1, dp[1][0] > dp[1][1], -1);
	sort(ans.begin(), ans.end());

	cout << max(dp[1][0], dp[1][1]) << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}

/*
만약 어떤 정점을 독립 집합에 포함시켰으면, 그 정점과 인접한 정점들은 독립 집합에 포함시킬 수 없습니다.
이를 이용하여 최대 독립 집합의 가중치 크기를 구해주었습니다.

dp[i][0] = 집합 i ~ N번에서 i번 노드가 선택되었을 때 최대 독립 집합 크기,
dp[i][1] = 집합 i ~ N번에서 i번 노드가 선택되지 않았을 때 최대 독립 집합 크기를 의미합니다.

어떤 정점을 선택했다면, 인접한 정점은 선택할 수 없습니다.
어떤 정점을 선택하지 않았다면, 인정한 정점은 선택할 수 도 있고, 선택하지 않을 수도 있습니다.
이를 이용하면, 현재 정점을 node, 인접한 정점을 next라고 할 때, 다음과 같은 점화식을 세울 수 있습니다.
dp[node][0] += dp[next][1]; // 현재 정점을 선택했으므로 인접한 정점은 선택할 수 없음
dp[node][1] += max(dp[next][0], dp[next][1]);  // 현재 정점을 선택하지 않았으므로 인접한 정점을 선택했던 경우와 선택하지 않았던 경우 중에 더 큰 값으로 결정

1번 정점에서부터 깊이 우선 탐색으로 리프 노드까지 순회한 뒤,
역으로 빠져나오며 dp값을 업데이트해줌으로써 최대 독립 집합의 크기는 max(dp[1][0], dp[1][1])이 됩니다.

최대 독립 집합에 포함된 정점들은 다음과 같이 구할 수 있습니다.
i번 정점에서 순회를 시작한다고 했을 때, i번 정점이 집합에 포함되었거나 포함되지 않은 두 가지 상황으로 나뉘게 됩니다.
1) dp[i][0] > dp[i][1]이라면, i번 정점은 집합에 포함되어 있습니다.
    i번 정점이 포함되었으므로 i번과 인접한 정점들은 집합에 포함될 수 없다는게 자명합니다.
2) dp[i][0] < dp[i][1]이라면, i번 정점은 집합에 포함되어 있지 않습니다.
    i번 정점이 포함되어 있지 않으므로, i번과 인접한 정점들은 집합에 포함될 수도 있고 포함되지 않을 수도 있습니다.
인접한 정점들을 j라고 할 때, dp[j][0] > dp[j][1]이라면, j번 정점은 집합에 포함되어 있습니다.

위와 같은 방식으로 최대 독립 집합의 크기를 구했던 상황을 역추적함으로써 포함된 정점들을 구할 수 있습니다. 
*/