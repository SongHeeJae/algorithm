#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define MAX 26
using namespace std;

int n, num;
vector<vector<int>> graph;
int id[MAX] = { 0 };
int sccIdx[MAX] = { 0 };
vector<vector<int>> scc;
bool exist[MAX] = { false };
stack<int> stk;

int dfs(int node) {
	id[node] = num++;
	stk.push(node);

	int res = id[node];

	for (int nxt : graph[node]) {
		if (id[nxt] == 0) res = min(res, dfs(nxt));
		else if (!sccIdx[nxt]) res = min(res, id[nxt]);
	}

	if (res == id[node]) {
		vector<int> temp;
		int idx = scc.size() + 1;
		while (1) {
			int top = stk.top();
			stk.pop();
			sccIdx[top] = idx;
			temp.push_back(top);
			if (top == node) break;
		}
		scc.push_back(temp);
	}

	return res;
}

void createScc() {
	for (int i = 0; i < 26; i++) {
		if (id[i] == 0) {
			dfs(i);
		}
	}
}

void sortSccOrderByAsc() {
	for (auto& sc : scc) {
		sort(sc.begin(), sc.end());
	}
	sort(scc.begin(), scc.end());
}

void init() {
	num = 1;
	memset(id, 0, sizeof(id));
	memset(sccIdx, 0, sizeof(sccIdx));
	memset(exist, false, sizeof(exist));
	scc.clear();
	graph.clear();
	graph.resize(MAX);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		init();

		cin >> n;
		if (n == 0) break;

		
		for (int i = 0; i < n; i++) {
			char sel, q[5];
			for (int j = 0; j < 5; j++) {
				cin >> q[j];
				exist[q[j] - 'A'] = true;
			}
			cin >> sel;
			for (int j = 0; j < 5; j++) {
				if (sel == q[j]) continue;
				graph[sel - 'A'].push_back(q[j] - 'A');
			}
		}

		createScc();

		sortSccOrderByAsc();

		for (auto& sc : scc) {
			if (sc.size() == 1 && !exist[sc.front()]) continue;
			for (auto s : sc) {
				cout << char(s + 'A') << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

/*
질문의 항목들이 X이고, 그 질문에 대한 선택을 Y라고 할 때,
Y가 X보다 우선순위가 높음을, Y -> X 간선으로 표시해주었습니다.
어떤 질문 간에 모순이 발생한 것은, 그래프에서 사이클이 발생한 것과 같습니다.
따라서 질문들을 scc로 묶어준 뒤, 오름차순 정렬하여 출력해주었습니다. 
*/