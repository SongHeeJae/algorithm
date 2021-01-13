#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, a, s = 0;
	scanf("%d", &n);
	stack<int> stk;
	while (n--) {
		scanf("%d", &a);
		if (a) stk.push(a);
		else stk.pop();
	}
	while (!stk.empty()) {
		s += stk.top();
		stk.pop();
	}
	printf("%d\n", s);

}