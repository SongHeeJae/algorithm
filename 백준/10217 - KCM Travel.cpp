#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

class Data {
public:
	int v, c, d; // 출발점, 비용, 시간
	Data(int v, int c, int d) : v(v), c(c), d(d) {}
	bool operator< (const Data& D) const {
		if (d > D.d) return 1;
		else return 0;
	}
};

int KCMTravel(vector<vector<Data>>& graph, int start, int m) {
	vector<vector<int>> cache(graph.size(), vector<int>(m + 1, INF));

	// cache[i][j] 시작지점에서 i까지 j원의 비용으로 갈 수 있는 최소 거리
	cache[start][0] = 0;
	priority_queue<Data, vector<Data>> pq;

	// 출발점, 비용, 시간
	pq.push(Data(start, 0, 0));
	while (!pq.empty()) {
		int v = pq.top().v;
		int c = pq.top().c;
		int d = pq.top().d;
		pq.pop();

		if (v == graph.size() - 1) break;

		// m보다 c가 크면 continue;
		if (cache[v][c] < d || c > m) continue;

		for (int i = 0; i < graph[v].size(); i++) {
			int nextV = graph[v][i].v;
			int nextC = graph[v][i].c;
			int nextD = graph[v][i].d;
			
			// 거리 가중치, 비용 비교
			if (c + nextC <= m && cache[nextV][c + nextC] > d + nextD) {
				cache[nextV][c + nextC] = d + nextD;
				pq.push(Data(nextV, c + nextC, d + nextD));
			}
		}
	}

	int ans = INF;
	for (int i = 0; i <= m; i++)
		ans = min(ans, cache[graph.size() - 1][i]);
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, k, u, v, c, d;
		scanf("%d %d %d", &n, &m, &k);
		vector<vector<Data>> graph(n + 1, vector<Data>());
		while (k--) {
			scanf("%d %d %d %d", &u, &v, &c, &d);
			graph[u].push_back(Data(v, c, d));
		}
		int ans = KCMTravel(graph, 1, m);
		if (ans != INF) printf("%d\n", ans);
		else printf("Poor KCM\n");
	}
}