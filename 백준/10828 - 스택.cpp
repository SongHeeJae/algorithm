#include <iostream>
#include <cstring>
int num = 0;
int stk[10001];

void push(int n) {
	stk[num++] = n;
}

void top() {
	printf("%d\n", num > 0 ? stk[num - 1] : -1);
}

void size() {
	printf("%d\n", num);
}

void empty() {
	printf("%d\n", num > 0 ? 0 : 1);
}

void pop() {
	printf("%d\n", num > 0 ? stk[--num] : -1);
}

int main() {
	int n, a;
	char comm[10];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", comm, sizeof(comm));
		if (strcmp(comm, "top") == 0) top();
		else if (strcmp(comm, "size") == 0) size();
		else if (strcmp(comm, "pop") == 0) pop();
		else if (strcmp(comm, "empty") == 0) empty();
		else {
			scanf("%d", &a);
			push(a);
		}
	}
}