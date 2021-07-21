#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int p[100001][17]; // p[i][j] = i번 노드의 2^j번 조상 노드
int d[100001]; // d[i] = i번 노드의 깊이
long long c[100001]; // c[i] = 1번 노드부터 i번 노드까지의 누적 비용
vector<pair<int, int>> graph[100001];

void init(int node, int depth, long long cost) {
	d[node] = depth;
	c[node] = cost;
	for (auto& edge: graph[node]) {
		int nxt = edge.first;
		int cst = edge.second;
		if (d[nxt] != -1) continue;
		p[nxt][0] = node;
		init(nxt, depth + 1, cost + cst);
	}
}

int lca(int a, int b) {
	if (d[a] > d[b]) swap(a, b);
	int diff = d[b] - d[a];
	for (int i = 0; diff != 0; i++) {
		if (diff & 1) {
			b = p[b][i];
		}
		diff >>= 1;
	}
	if (a == b) return a;
	for (int i = 16; i >= 0; i--) {
		if (p[a][i] != p[b][i]) {
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

int getKth(int a, int b, int l, int k) {
	// a = 출발점, b = 도착점, l = lca, k = k번째
	// 다음과 같은 세 가지 상황으로 나뉜다.
	// 1) lca가 k번째인 경우
	//  * lca가 k번째이다.
	// 2) 출발점 ~ lca 사이에 k번째가 포함된 경우
	//  * 출발점에서 k번째 조상노드를 찾아준다.
	// 3) lca ~ 도착점 사이에 k번째가 포함된 경우
	//  * lca와 a, b 사이의 깊이 차이, k를 이용해서
	//    도착점에서 역으로 올라와야할 값을 구하여 k번째를 구해준다.

	int adiff = d[a] - d[l];
	k--;
	if (adiff == k) return l; // 출발점 ~ lca까지가 k번째인 경우
	else if (adiff < k){ // lca ~ 도착점 사이에 k번째가 포함된 경우
		int bdiff = d[b] - d[l];
		k = adiff + bdiff - k; // 도착점에서 이만큼 올라오면 k번째
		a = b;
	}

	// 출발점 또는 도착점에서 k만큼 올라온다.
	for (int i = 0; k != 0; i++) {
		if (k & 1) {
			a = p[a][i];
		}
		k >>= 1;
	}
	return a;
}

long long getCost(int a, int b, int l) {
	// a = 출발점, b = 도착점, l = lca
	// (( 1 ~ a까지의 비용 ) - ( 1 ~ lca까지의 비용 ))
	//   + (( 1 ~ b까지의 비용 ) - ( 1 ~ lca까지의 비용 )) 
	return c[a] + c[b] - c[l] * 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int u, v, w, op, k;

	memset(d, -1, sizeof(d));
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	init(1, 0, 0);

	for (int i = 1; i < 17; i++) {
		for (int j = 1; j <= n; j++) {
			p[j][i] = p[p[j][i - 1]][i - 1];
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> op >> u >> v;
		int res = lca(u, v);
		if (op == 1) {
			cout << getCost(u, v, res) << "\n";
		} else {
			cin >> k;
			cout << getKth(u, v, res, k) << "\n";
		}
	}
}


/*
먼저 1번 노드에서 시작하여 각 노드의 깊이와 sparse table, 1번 노드부터 N번 노드까지의 누적 비용 합을 초기화시켜줍니다.

cost[i] = 1번 노드부터 i번 노드까지의 누적 비용 합이라고 할 때,
1 u v는 다음과 같이 구할 수 있습니다.
(1번 노드부터 u번 노드까지의 누적 비용 합 - 1번 노드부터 lca 노드까지의 누적 비용합)
  + (1번 노드부터 v번 노드까지의 누적 비용 합 - 1번 노드부터 lca 노드까지의 누적 비용합) 이므로
1 u v 쿼리 결과 = c[u] + c[v] - c[lca] * 2가 됩니다.

k번째 노드의 번호를 구할 때도 LCA를 이용할 수 있습니다.
2 u v k 쿼리를 수행할 때, 다음과 같은 세 가지 케이스로 나뉘게 됩니다.
1) lca가 k번째인 경우
 * lca가 k번째이다.
2) 출발점 ~ lca 사이에 k번째가 포함된 경우
 * 출발점에서 k번째 조상노드를 찾아준다.
3) lca ~ 도착점 사이에 k번째가 포함된 경우
 * lca와 a, b 사이의 깊이 차이, k를 이용해서 도착점에서 역으로 올라와야할 값을 구하여 k번째를 구해준다.
k번째가 어떤 케이스에 포함되는지는, 처음에 초기화해둔 각 노드별 깊이를 이용하여 구할 수 있습니다.
*/