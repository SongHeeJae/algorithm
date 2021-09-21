#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

int n, m, k, visit[MAX] = { 0 };
vector<int> haters[MAX];

void dfs(int node, int team) {
	visit[node] = team;
	for (auto nxt : haters[node]) {
		if (visit[nxt]) continue;
		dfs(nxt, -team);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		while (m--) {
			scanf("%d", &k);
			haters[i].push_back(k);
			haters[k].push_back(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) dfs(i, i % 2 ? 1 : -1);
	}

	vector<int> blue, white;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 1) blue.push_back(i);
		else white.push_back(i);
	}

	printf("%d\n", blue.size());
	for (auto i : blue) printf("%d ", i);
	printf("\n%d\n", white.size());
	for (auto i : white) printf("%d ", i);
}

/*
싫어하는 관계를 그래프로 만들고,
현재 노드와 다음 노드를 다른 팀으로 배정해주었습니다.
*/