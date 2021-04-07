#include <iostream>
int n, a, top = -1;
std::pair<int, int> stk[500000];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n && scanf("%d", &a); i++) {
		while (top != -1 && stk[top].first < a) top--;
		if (top == -1) printf("0 ");
		else printf("%d ", stk[top].second);
		stk[++top] = { a, i };
	}
}