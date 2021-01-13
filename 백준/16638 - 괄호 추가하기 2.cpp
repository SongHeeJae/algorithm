#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
int n, ans = -2147483648, pos[23];
// pos[i] == i번째 위치의 괄호 0이면 없음. -1이면 열림. 1이면 닫힘.
string infix, postfix, s;
int priority(char ch) {
	if (ch == '*') return 2;
	else if (ch == '+' || ch == '-') return 1;
	else return 0;
}

void infixToPostfix() {
	postfix = "";
	stack<char> stk;

	for (int i = 0; i < infix.size(); i++) {
		char ch = infix[i];
		if (ch == '+' || ch == '-' || ch == '*') {
			while (!stk.empty()) {
				char top = stk.top();
				if (priority(top) < priority(ch)) break;
				stk.pop();
				postfix.push_back(top);
			}
			stk.push(ch);
		}
		else if (ch == '(') stk.push(ch);
		else if (ch == ')') {
			while (1) {
				char top = stk.top();
				stk.pop();
				if (top == '(') break;
				postfix.push_back(top);
			}
		}
		else postfix.push_back(ch);

	}

	while (!stk.empty()) {
		char top = stk.top();
		stk.pop();
		postfix.push_back(top);
	}
}

void cal() {
	infixToPostfix();
	stack<int> stk;
	for (int i = 0; i < postfix.size(); i++) {
		char ch = postfix[i];
		if ('0' <= ch && ch <= '9') stk.push(ch - '0');
		else {
			int op1 = stk.top(); stk.pop();
			int op2 = stk.top(); stk.pop();
			if (ch == '+') stk.push(op1 + op2);
			else if (ch == '-') stk.push(op2 - op1);
			else stk.push(op1 * op2);
		}
	}
	ans = max(ans, stk.top());
}

void f(int c) {
	if (c == n + 1) {
		infix = s;
		int j = 0;
		for (int i = 0; i <= n; i++) {
			if (pos[i] != 0) {
				infix = infix.substr(0, i + j) + (pos[i] == -1 ? '(' : ')') + infix.substr(i + j);
				j++;
			}
		}
		cal();
		return;
	}
	else if (c > n + 1) return;
	pos[c] = -1;
	pos[c + 3] = 1;
	f(c + 4);
	pos[c] = 0;
	pos[c + 3] = 0;
	f(c + 2);
}

int main() {
	cin >> n >> s;
	f(0);
	cout << ans;
}