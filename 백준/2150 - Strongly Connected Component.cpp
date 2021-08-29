#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

int v, e, num = 1;
int id[MAX] = { 0 };
bool finished[MAX] = { false };
vector<int> graph[MAX];
vector<vector<int>> scc;
stack<int> stk;

int dfs(int node) {
	id[node] = num++;
	stk.push(node);

	int res = id[node];
	for (auto nxt : graph[node]) {
		if (id[nxt] == 0) {
			res = min(res, dfs(nxt));
		}
		else if (!finished[nxt]) { // 방문 했었지만 SCC에 포함되지 않은 노드인 경우
			res = min(res, id[nxt]);
		}
	}

	if (res == id[node]) {
		vector<int> temp;
		while (1) {
			int top = stk.top();
			stk.pop();
			finished[top] = true;
			temp.push_back(top);
			if (top == node) break;
		}
		scc.push_back(temp);
	}

	return res;
}

int main() {
	scanf("%d %d", &v, &e);

	for (int i = 0; i < e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
	}

	for (int i = 1; i <= v; i++) {
		if (id[i] == 0) dfs(i);
	}

	for (auto& s : scc) {
		sort(s.begin(), s.end());
	}
	sort(scc.begin(), scc.end());

	printf("%d\n", scc.size());
	for (auto& s : scc) {
		for (auto e : s) {
			printf("%d ", e);
		}
		printf("-1\n");
	}
}

/*
타잔 알고리즘으로 SCC들을 구해주었습니다.
방문하는 노드를 스택에 담아주면서 순서대로 번호를 붙여주고,
이미 방문했던 노드를 만난다면 현재 노드와 방문했던 노드의 번호 중에 더 작은 값을 리턴해줍니다.
리턴 값과 현재 노드의 번호가 같다면, 현재 노드가 나올 때까지 스택에 담긴 값들을 하나의 SCC로 묶어줍니다.
*/