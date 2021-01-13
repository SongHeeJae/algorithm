#include <iostream>
#include <vector>
using namespace std;
int n, a, b;
vector<vector<int>> graph(1000001, vector<int>());
long long int ans[1000001] = { 0, };
bool visited[1000001] = { false, };

// ans[i] = 2(n-1) + 2(s.1 * s.2 + s.1 * s.3 + s.k-1 * s.k)
// s.k는 서브트리 k가 가지고 있는 정점의 개수
// ex) s.1*s.2 + s.1*s.3 + s.2*s.3

int dfs(int node) {
	visited[node] = true;
	long long int c = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		if (!visited[graph[node][i]]) {
			int cc = dfs(graph[node][i]); // cc는 지금 서브트리가 가진 정점의개수
			ans[node] += c * cc;
			c += cc;
		}
	}
	// n-c 반대쪽 서브트리가 가진 정점의 개수
	ans[node] += c*(n-c);
	return c;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
		cout << ans[i] * 2<< "\n";
}