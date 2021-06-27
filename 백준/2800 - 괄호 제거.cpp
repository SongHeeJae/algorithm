#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
using namespace std;

string expr;
vector<pair<int, int>> pairs;
vector<string> ans;
set<string> dup;
bool chk[200] = { false };

void init() {
	stack<int> stk;
	for (int i = 0; i < expr.size(); i++) {
		if (expr[i] == '(') {
			stk.push(i);
		}
		else if (expr[i] == ')') {
			pairs.push_back({ stk.top(), i });
			stk.pop();
		}
	}
}

void remove(int idx) {
	if (pairs.size() == idx) {
		string temp = "";
		for (int i = 0; i < expr.size(); i++) {
			if (!chk[i]) {
				temp.push_back(expr[i]);
			}
		}
		dup.insert(temp);
		return;
	}
	remove(idx + 1);
	chk[pairs[idx].first] = chk[pairs[idx].second] = true;
	remove(idx + 1);
	chk[pairs[idx].first] = chk[pairs[idx].second] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> expr;
	init();
	remove(0);
	for (auto it = dup.begin(); it != dup.end(); it++) {
		ans.push_back(*it);
	}
	sort(ans.begin(), ans.end());
	for (int i = 1; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}

/*
모든 괄호 쌍의 위치를 기억해둔 뒤, 괄호를 제거하는 모든 경우의 문자열을 구해주었습니다.
동일한 문자열은 set을 이용해서 중복을 제거해주었습니다.
*/