#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define NOT 1000
#define MAX 2 * NOT + 1
using namespace std;

int n, m, num = 1;
int id[MAX];
int finished[MAX];
vector<vector<int>> graph;
vector<vector<int>> scc;
stack<int> stk;

int notValue(int val) {
	if (val > NOT) return val - NOT;
	else return val + NOT;
}

int fitValue(int val) {
	if (val < 0) return -val + NOT;
	else return val;
}

int dfs(int node) {
	id[node] = num++;
	stk.push(node);

	int res = id[node];

	for (int nxt : graph[node]) {
		if (id[nxt] == 0) res = min(res, dfs(nxt));
		else if (!finished[nxt]) res = min(res, id[nxt]);
	}

	if (res == id[node]) {
		vector<int> temp;
		int idx = scc.size() + 1;
		while (1) {
			int top = stk.top();
			stk.pop();
			finished[top] = idx;
			temp.push_back(top);
			if (top == node) break;
		}
		scc.push_back(temp);
	}

	return res;
}

void createScc() {
	for (int i = 1; i <= n; i++) {
		if (id[i] == 0) dfs(i);
		if (id[notValue(i)] == 0) dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> n >> m) {
		num = 1;
		memset(id, 0, sizeof(id));
		memset(finished, 0, sizeof(finished));
		graph.clear();
		graph.resize(MAX);
		scc.clear();

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			a = fitValue(a);
			b = fitValue(b);
			graph[notValue(a)].push_back(b);
			graph[notValue(b)].push_back(a);
		}
		graph[notValue(1)].push_back(1);

		createScc();

		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (finished[i] == finished[notValue(i)]) {
				flag = false;
				break;
			}
		}

		cout << (flag ? "yes" : "no") << "\n";
	}
}

/*
심사위원이 내야하는 두 개의 표 중 하나는 결과에 영향을 미쳐야하므로, 하나의 OR 절로 묶어낼 수 있습니다.
모든 심사위원의 투표 결과로 진출 목록을 만들어내야하므로 2-SAT 문제로 볼 수 있습니다.
진출 목록을 만들 수 있는지 없는지 확인하는 것뿐만 아니라, 상근이도 진출 목록에 포함되어야합니다.
이를 판별하기 위해 (1 or 1) 절로 만들어지는 간선을 임의로 추가하여 진출 목록을 모순 없이 만들어낼 수 있는지 확인해주었습니다.
*/