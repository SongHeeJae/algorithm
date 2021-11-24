#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1001
using namespace std;

int n, m, s, t, c, ans = 0;
int indegree[MAX], sum[MAX];
vector<pair<int, int>> graph[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	while (m--) {
		cin >> s >> t >> c;
		graph[s].push_back({ t, c });
		indegree[t]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto& p : graph[x]) {
			int nxt = p.first;
			int cost = p.second;
			if (--indegree[nxt] == 0) q.push(nxt);
			sum[nxt] = max(sum[nxt], sum[x] + cost);
		}
		ans = max(ans, sum[x]);
	}
	cout << ans;
}

/*
위상정렬과 다이나믹프로그래밍을 이용한 문제였습니다.

지점 x로 진입할 수 있는 이전 지점을 y라고 하고, 지점 y에서 지점 x로 진입할 때 얻을 수 있는 점수를 c라고 한다면,
지점 x에서 얻을 수 있는 최대 점수 dp[x]는 다음과 같이 구할 수 있습니다.
dp[x] = max({ dp[<지점 x로 진입할 수 있는 모든 지점 y>] + c})
  = max(dp[x], dp[y] + c)
이를 이용하여 dp[x]가 최대가 될 때의 점수를 구해주었습니다.

위상정렬을 이용하여 산의 정상에서부터 계곡까지 내려가며 값을 업데이트해주었습니다.
*/