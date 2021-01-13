#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
int n, ans = -2147483648, pos[23];
// pos[i] == i번째 위치의 괄호 0이면 없음. -1이면 열림. 1이면 닫힘.
string infix, postfix, s;
int priority(char ch) {
	if (ch == '+' || ch == '-' || ch == '*') return 1;
	else return 0;
}

void infixToPostfix() { // 중위표기식을 후위표기식으로 변환
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

void cal() { // 계산
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
	if (c == n + 1) { // 괄호 조합 생성
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
	else if (c > n + 1) return; // 괄호가 제대로 닫히지 않은 경우
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

/*

가능한 모든 괄호의 조합을 생성해내고, 생성된 괄호 조합으로 수식을 만들어내었습니다.
그 후, 스택을 이용하여 그 수식을 계산해냈습니다.

문제를 제대로 읽지 않아서 아래와 같은 사항을 인지하지 못하였습니다.
그래서 해답을 찾는데 더욱 오래 걸렸던 것 같습니다.

 1. 괄호 안에는 연산자가 하나만 있어야한다. 
 2. 중첩 괄호는 허용하지 않는다.
 4. 연산자 '+', '-', '*'의 우선순위는 모두 동일하다.
 3. 정답은 2^31보다 작고, -2^31 보다 크다.

위 사항을 준수하고 있으면 될 것 같습니다.
*/