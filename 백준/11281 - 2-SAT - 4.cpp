#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define NOT 10000
#define N_MAX NOT + 1
#define MAX 2 * NOT + 1
using namespace std;

int n, m, num = 1;
int id[MAX] = { 0 };
int finished[MAX] = { 0 };
vector<int> graph[MAX];
vector<vector<int>> scc;
stack<int> stk;
bool value[N_MAX];
bool visit[N_MAX] = { false };

bool isNotValue(int val) {
	return val > NOT;
}

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

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a = fitValue(a);
		b = fitValue(b);
		graph[notValue(a)].push_back(b);
		graph[notValue(b)].push_back(a);
	}

	createScc();

	for (int i = 1; i <= n; i++) {
		if (finished[i] == finished[notValue(i)]) {
			cout << "0";
			return 0;
		}
	}

	cout << "1\n";
	for (auto sc : scc) {
		for (auto s : sc) {
			bool isNot = isNotValue(s);
			s = isNot ? notValue(s) : s;
			if (visit[s]) continue;
			value[s] = !isNot;
			visit[s] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << value[i] << " ";
	}
}

/*
x_i의 값을 구하기 위해서 scc를 활용하였습니다.
아직 값이 결정되지 않았으면서 동일한 scc에 속한 변수의 노드 값이 true를 가지도록 해주었습니다.
*/