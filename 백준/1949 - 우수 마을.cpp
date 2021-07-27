#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[10001][2];
int n, a, b;
vector<int> graph[10001];

void init(int node, int prev) {
	for (int next : graph[node]) {
		if (next == prev) continue;
		init(next, node);
		dp[node][0] += dp[next][1];
		dp[node][1] += max(dp[next][0], dp[next][1]);
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

	cout << max(dp[1][0], dp[1][1]) << "\n";
}

/*
풀이는 다음 링크와 동일합니다.
https://blog.naver.com/gmlwo308/222445300712
*/