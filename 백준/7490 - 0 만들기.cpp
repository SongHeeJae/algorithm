#include <iostream>
#include <vector>
using namespace std;

char op[] = "+-";
int t, n;
vector<int> expr;
string buf;

int calc() {
	int res = expr[0];
	for (int i = 2; i < expr.size(); i+=2) {
		if (-expr[i - 1] == '+') res += expr[i];
		else res -= expr[i];
	}
	return res;
}

void dfs(int depth) {
	if (depth == n) {
		if (calc() == 0) cout << buf << "\n";
		return;
	}
	int back = expr.back();
	expr.pop_back(); expr.push_back(back * 10 + depth + 1);
	buf.push_back(' '); buf.push_back(depth + 1 + '0');
	dfs(depth + 1);
	buf.pop_back(); buf.pop_back();
	expr.pop_back(); expr.push_back(back);
	for (int i = 0; i < 2; i++) {
		expr.push_back(-op[i]); expr.push_back(depth + 1);
		buf.push_back(op[i]); buf.push_back(depth + 1 + '0');
		dfs(depth + 1);
		expr.pop_back(); expr.pop_back();
		buf.pop_back(); buf.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		expr.push_back(1); buf.push_back('1');
		dfs(1);
		expr.pop_back(); buf.pop_back();
		cout << "\n";
	}
}

/*
만들 수 있는 모든 수식을 만들고, 그 수식의 계산식이 0인지 확인해주었습니다. 
*/