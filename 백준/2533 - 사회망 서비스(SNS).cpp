#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a, b;
vector<int> graph[1000001];
bool visit[1000001] = { false };
int dp[1000001][2];

void dfs(int node) {
	visit[node] = true;
	dp[node][0] = 1;
	dp[node][1] = 0;
	for (auto child : graph[node]) {
		if (visit[child]) continue;
		dfs(child);
		dp[node][0] += min(dp[child][0], dp[child][1]);
		dp[node][1] += dp[child][0];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	printf("%d", min(dp[1][0], dp[1][1]));
}

/*
자신이 얼리 아답터라면, 친구들은 얼리 아답터이거나 얼리 아답터가 아닙니다.
자신이 얼리 아답터가 아니라면, 친구들은 얼리 아답터입니다.

dp[i][0] = i가 얼리 아답터일 때, 자식 노드에서 나타날 수 있는 얼리 아답터의 최소 수,
dp[i][1] = i가 얼리 아답터가 아닐 때, 자식 노드에서 나타날 수 있는 얼리 아답터의 최소 수 입니다.

dfs로 노드의 끝에 도달한 뒤, 빠져나오면서 각 노드의 자식 노드에서 업데이트 되어있는 얼리 어답터의 최소 수를 이용하여 부모 노드에도 업데이트해줍니다.
*/