#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = -1;
int board[20][20];

void move(int c) { // 상
	if (c == 0) {
		for (int i = 0; i < n; i++) {
			int prev = board[0][i];
			int k = prev ? 1 : 0;
			for (int j = 1; j < n; j++) {
				if (board[j][i] != 0) {
					if (board[j][i] == prev) {
						board[k - 1][i] = prev * 2;
						prev = board[j][i] = 0;
					}
					else {
						int t = board[j][i];
						board[j][i] = 0;
						prev = board[k][i] = t;
						k++;
					}
				}
			}
		}
	}
	else if (c == 1) { // 하
		for (int i = 0; i < n; i++) {
			int prev = board[n - 1][i];
			int k = prev ? n - 2 : n - 1;
			for (int j = n - 2; j >= 0; j--) {
				if (board[j][i] != 0) {
					if (board[j][i] == prev) {
						board[k + 1][i] = prev * 2;
						prev = board[j][i] = 0;
					}
					else {
						int t = board[j][i];
						board[j][i] = 0;
						prev = board[k][i] = t;
						k--;
					}
				}
			}
		}
	}
	else if (c == 2) { // 좌
		for (int i = 0; i < n; i++) {
			int prev = board[i][0];
			int k = prev ? 1 : 0;
			for (int j = 1; j < n; j++) {
				if (board[i][j] != 0) {
					if (board[i][j] == prev) {
						board[i][k-1] = prev * 2;
						prev = board[i][j] = 0;
					}
					else {
						int t = board[i][j];
						board[i][j] = 0;
						prev = board[i][k] = t;
						k++;
					}
				}
			}
		}
	}
	else { // 우
		for (int i = 0; i < n; i++) {
			int prev = board[i][n-1];
			int k = prev ? n - 2 : n - 1;
			for (int j = n - 2; j >= 0; j--) {
				if (board[i][j] != 0) {
					if (board[i][j] == prev) {
						board[i][k+1] = prev * 2;
						prev = board[i][j] = 0;
					}
					else {
						int t = board[i][j];
						board[i][j] = 0;
						prev = board[i][k] = t;
						k--;
					}
				}
			}
		}
	}
}
void copy(int a[][20], int b[][20]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) a[i][j] = b[i][j];
}
void fun(int c) {
	if (c == 5) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) ans = max(ans, board[i][j]);
		return;
	}
	int temp[20][20];
	copy(temp, board);
	for (int i = 0; i < 4; i++) {
		move(i);
		fun(c + 1);
		copy(board, temp);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) scanf("%d", &board[i][j]);
	fun(0);
	printf("%d", ans);
}