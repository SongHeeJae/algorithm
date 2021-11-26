#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define N_MAX 10001
#define K_MAX 21
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, pii> plii;

int n, m, k, a, b, c;
vector<pii> graph[N_MAX];
ll dp[N_MAX][K_MAX];

void pushIfGreater(priority_queue<plii>& pq, int nxt, int kk, ll nxtCost) {
	if (dp[nxt][kk] > nxtCost) {
		dp[nxt][kk] = nxtCost;
		pq.push({ -nxtCost, {nxt, kk} });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(dp, 0x77, sizeof(dp));

	cin >> n >> m >> k;

	while (m--) {
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	priority_queue<plii> pq; // {cost, city, k}
	dp[1][0] = 0;
	pq.push({ 0, {1, 0} });
	while (!pq.empty()) {
		ll c = -pq.top().first;
		int x = pq.top().second.first;
		int kk = pq.top().second.second;
		pq.pop();

		if (dp[x][kk] < c) continue;

		for (auto& p : graph[x]) {
			int nxt = p.first;
			int cost = p.second;
			if(kk < k) pushIfGreater(pq, nxt, kk + 1, c);
			pushIfGreater(pq, nxt, kk, c + cost);
		}
	}

	ll mn = dp[n][0];
	for (int i = 1; i <= k; i++) {
		mn = min(mn, dp[n][i]);
	}
	cout << mn;
}

/*
다익스트라 알고리즘을 이용하여 풀이하였습니다.
dp[i][j] = 1번 도시에서 i번 도시로 갈 때, j개의 도로를 포장하여 얻을 수 있는 최소 비용입니다.
다익스트라를 수행하며, 도로를 포장했을 때와 도로를 포장하지 않았을 때의 두 가지 경우를 모두 우선순위 큐에 넣어줍니다.

위와 같이 아직 k개의 도로를 포장하지 않았다면, 두 가지 경우를 모두 검사하여 우선순위 큐와 dp 배열을 업데이트해줍니다.
updateIfGreater는 중복된 코드라 따로 함수로 추출하였는데,
단순히 dp와 pq를 업데이트해주는 함수입니다.

이렇게 얻은 dp 배열로, dp[n][0] ~ dp[n][k] 에서의 최솟값을 구해주면 K개 이하의 도로를 포장하여 얻을 수 있는 최소 비용을 구할 수 있습니다.

처음 단순하게 생각했을 때는, 무조건 더 많은 도로를 포장하는게 더욱 이득이지 않을까 싶어서,

dp[n][k]가 최소 비용을 보장할지 고민해보았는데, 안일한 생각이었습니다.
4 4 2
1 2 10
2 3 10
3 4 10
1 4 20
다음과 같은 경우가 있다면, 1-4 도로 1개만 포장된 경로로 이동하는 것이 최소 비용이 됩니다. 

늘 문제를 제대로 읽지 않아서 한 번씩 헤매곤 하는데, 주어진 도로 입력은 양방향임을 유의해야했습니다.
*/