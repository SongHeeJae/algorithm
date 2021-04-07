#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;
char buf[31];

bool isValidate() {
	for (int i = 0; buf[i] != '\0'; i++) {
		if (buf[i] == '(' || buf[i] == '[') stk.push(buf[i]);
		else {
			if (stk.empty()) return false;
			if (buf[i] == ')') {
				if (stk.top() != '(') return false;
			}
			else {
				if (stk.top() != '[') return false;
			}
			stk.pop();
		}
	}
	if (stk.empty()) return true;
	else return false;
}

int main() {
	scanf("%s", buf);
	if (!isValidate()) {
		printf("0");
		return 0;
	}
	for (int i = 0; buf[i] != '\0'; i++) {
		if(buf[i] == '(' || buf[i] == '[') stk.push(buf[i]);
		else {
			if (buf[i] == ')') {
				if (stk.top() < 0) {
					int sum = 0;
					while (!stk.empty() && stk.top() != '(') {
						if(stk.top() < 0) sum += stk.top();
						stk.pop();
					}
					if (!stk.empty() && stk.top() == '(') stk.pop();
					stk.push(2 * sum);
				}
				else {
					stk.pop();
					stk.push(-2);
				}
			}
			else if (buf[i] == ']'){
				if (stk.top() < 0) {
					int sum = 0;
					while (!stk.empty() && stk.top() != '[') {
						if (stk.top() < 0) sum += stk.top();
						stk.pop();
					}
					if (!stk.empty() && stk.top() == '[') stk.pop();
					stk.push(3 * sum);
				}
				else {
					stk.pop();
					stk.push(-3);
				}
			}
		}
	}
	int ans = 0;
	while (!stk.empty()) {
		if(stk.top() < 0) ans += stk.top();
		stk.pop();
	}
	printf("%d", -ans);
}