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
	for (int i = 0; i < m; i++) {
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
	cout << flag;
}

/*
주어진 식에서 2개의 변수로 이루어진 M개의 OR 절을 AND 연산을 했을 때, true가 나올 수 있는지 검사하는 문제였습니다.
따라서 모든 절은 true가 나와야하므로, 절 (a or b)에 대해서 a와 b 중 하나라도 true가 되어야합니다.
a가 false라면, b는 true여야합니다.
b가 false라면, a는 true여야합니다.
이러한 관계를 통해서 true에서 true로 가는 그래프의 간선을 만들어주면,
(~a -> b), (~b -> a)와 같은 형태의 간선을 만들어낼 수 있습니다.
모든 절에 대한 간선으로 그래프를 만들어주고, SCC를 구해줍니다.
어떤 변수 x에 대해서 x와 ~x가 같은 SCC에 속한다면,
(x -> ~x), (~x -> x) 두 경로가 모두 존재하므로 x와 ~x 모두 true가 되어야하는 모순이 발생하게 되면서,
주어진 식을 true로 만들 수 없게 됩니다.
*/