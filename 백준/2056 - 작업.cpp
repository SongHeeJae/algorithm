#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

int n, m, a, ans = 0, dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int mx = 0;
		cin >> dp[i] >> m;
		while (m--) {
			cin >> a;
			mx = max(mx, dp[a]);
		}
		dp[i] += mx;
		ans = max(ans, dp[i]);
	}
	cout << ans;
}

/*
문제 조건에 의하면, K번 작업의 선행 작업들의 번호는 반드시 1이상 (K-1)이하입니다.

따라서, K번 작업의 최소 소요 시간은,
((K번 작업의 작업 시간) + (1이상 K-1번 작업들의 최소 소요 시간)) 이 됩니다.
dp[K]를 구할 때, dp[<1 ~ (K-1)>]은 이미 구해져있기 때문입니다.

즉,
dp[K] = max({ dp[<K번 작업의 선행 작업들>] + t[K] }) 로 구할 수 있었습니다.


---

다음과 같은 방식으로도 풀 수 있었습니다.
위상정렬을 이용하여 풀이하였습니다.
x로 진입하는 노드는 y이고, x번 노드의 작업 소요 시간을 t[x]라고 할 때,
dp[x] = x번 작업을 완료하기 위해 필요한 최소 시간
  = max(dp[x], dp[y] + t[x])
를 이용하여 각 작업이 걸리는 최대 시간을 구할 수 있습니다.
한 가지 실수했던 점은, 마지막에 방문한 노드라고 해서 꼭 그것이 가장 마지막에 끝나는 작업은 아니었다는 것입니다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10001
using namespace std;

int n, m, a, t[MAX];
int indegree[MAX];
int dp[MAX];
vector<int> graph[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> m;
		while (m--) {
			cin >> a;
			graph[a].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			dp[i] = t[i];
			q.push(i);
		}
	}

	int ans = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int nxt : graph[x]) {
			if (--indegree[nxt] == 0) q.push(nxt);
			dp[nxt] = max(dp[nxt], dp[x] + t[nxt]);
		}
		ans = max(ans, dp[x]);
	}
	cout << ans;
}
*/