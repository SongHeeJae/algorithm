#include <iostream>
#include <vector>
using namespace std;
#define MAX 500001

int n, a, b, leafCnt = 0, leafDepth = 0;
vector<int> graph[MAX];

void calTotalLeafDepthAndLeafCnt(int node, int prv, int d) {
	bool hasChild = false;
	for (auto nxt : graph[node]) {
		if (nxt == prv) continue;
		hasChild = true;
		calTotalLeafDepthAndLeafCnt(nxt, node, d + 1);
	}
	if (!hasChild) {
		leafCnt++;
		leafDepth += d;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	calTotalLeafDepthAndLeafCnt(1, -1, 1);
	if ((leafDepth + leafCnt) % 2) cout << "Yes";
	else cout << "No";
}


/*
리프 노드의 개수와 모든 리프 노드 깊이의 합으로 게임을 이길 수 있는지 구해주었습니다.
*/