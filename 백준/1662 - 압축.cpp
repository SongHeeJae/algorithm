#include <iostream>
#include <stack>
using namespace std;

string s;
int ans = 0;
stack<int> stk;

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ')') {
			int cnt = 0;
			while (!stk.empty()) {
				int top = stk.top();
				stk.pop();
				if (top == '(') break;
				else if (top < 0) {
					cnt += -top;
				}
				else {
					cnt++;
				}
			}
			int k = stk.top() - '0';
			stk.pop();
			if(k != 0 && cnt != 0) stk.push(-cnt * k);
		}
		else {
			stk.push(s[i]);
		}
	}
	while (!stk.empty()) {
		int top = stk.top();
		stk.pop();
		if (top < 0) ans += -top;
		else ans++;
	}
	printf("%d", ans);
}

/*
여는 괄호나 숫자가 나오면 스택에 담아줍니다.
닫는 괄호가 나오면 여는 괄호가 나올 때까지 숫자의 개수를 세줍니다. (음수라면 그 숫자를 양수로 바꿔서 그대로 더해줍니다.)
세어진 숫자의 개수와 지금 스택의 탑에 위치한 K를 곱해서 스택에 담아줍니다.
모든 괄호를 없애준 뒤, 스택의 최종 상태에서 문자열의 길이를 구해주면 됩니다.

몇 가지 반례를 못 찾고 있었는데,
0(3)
3()
위와 같은 경우 0이 나오도록 해주면 되었습니다.
*/