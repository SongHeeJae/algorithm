#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define NOT 10000
#define MAX 2 * NOT + 1
using namespace std;

int n, m, num = 1;
int id[MAX] = { 0 };
int finished[MAX] = { 0 };
vector<int> graph[MAX];
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

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a = fitValue(a);
		b = fitValue(b);
		graph[notValue(a)].push_back(b);
		graph[notValue(b)].push_back(a);
	}

	createScc();

	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (finished[i] == finished[notValue(i)]) {
			flag = false;
			break;
		}
	}

	cout << (flag ? "^_^" : "OTL");
}

/*
한 학생은 두 종류의 선택 중 하나라도 맞추면 살 수 있습니다.
N명의 학생 각각이 두 종류의 선택 중 하나라도 맞춰내면, 모든 학생이 살아남을 수 있습니다.
N개의 OR절이 있고, 각 절마다 가위 또는 바위인지 하나를 맞춰야하므로 2-SAT 문제로 볼 수 있었습니다.
*/