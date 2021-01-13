#include <iostream>
using namespace std;

bool promising(int col[], int c) {
	for (int i = 0; i < c; i++)
		if (col[i] == col[c] || abs(col[c] - col[i]) == abs(i - c)) return false;
	return true;
}

int queenCount(int col[], int n, int c) {
	if (c == n) return 1;

	int count = 0;
	for (int i = 0; i < n; i++) {
		col[c] = i;
		if (promising(col, c)) count += queenCount(col, n, c + 1);
	}

	return count;
}

int main() {
	int n;
	scanf("%d", &n);
	int col[15] = { 0, };
	printf("%d\n", queenCount(col, n, 0));
}