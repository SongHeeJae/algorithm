#include <iostream>
#include <vector>
using namespace std;

int n, m, k, a;
bool known[51] = { false }; // known[i] = 진실은 아는 i번 사람은 true
vector<int> party[51]; // party[i] = i번 파티에 참석한 사람들
vector<int> joined[51]; // joined[i] = i번 사람이 참석한 파티 번호
bool notOvered[51] = { false }; // notOvered[i] = i번 파티가 과장되지 않았으면 true
bool visit[51] = { false };

void dfs(int node) {
	if (visit[node]) return;
	visit[node] = true;
	for (auto partyNum : joined[node]) {
		notOvered[partyNum] = true;
		for (auto nodeNum : party[partyNum]) {
			dfs(nodeNum);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &a);
		known[a] = true;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &k);
		while (k--) {
			scanf("%d", &a);
			party[i].push_back(a);
			joined[a].push_back(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (known[i]) dfs(i);
	}

	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (!notOvered[i]) cnt++;
	}
	printf("%d", cnt);
}

/*
먼저 이야기의 진실을 아는 사람을 기억해둡니다.
각 파티와 파티에 참석한 사람들을 입력받을 때는, 각 사람이 참석한 파티들, 각 파티에 참석한 사람들을 기억해줍니다.
진실을 아는 사람이 참석한 모든 파티를 검사하면서, 그 모든 파티에 참석한 사람들이 참석했던 모든 파티들을 검사해줍니다.
그러면 진실을 아는 사람이 참석했던 파티로 인해 모든 연관을 맺은 사람들이 참석했던 파티를 알게 됩니다.  
*/