#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int> stk;
vector<char> ans;
int num = 1;
void push() {
	ans.push_back('+');
	stk.push(num++);
}
void pop() {
	ans.push_back('-');
	stk.pop();
}

int main() {
	int n, a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (num <= a) {
			while (num <= a) push();
			pop();
		}
		else {
			while (!stk.empty() && stk.top() != a) pop();
			if (stk.empty()) {
				printf("NO");
				return 0;
			}
			pop();
		}
	}
	for (char c : ans) printf("%c\n", c);
}