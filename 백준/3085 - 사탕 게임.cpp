#include <iostream>
#include <algorithm>
using namespace std;

int n;
char board[50][50];
int ans = 1;
int dx[] = { 0,1 };
int dy[] = { 1,0 };


void candy(int x, int y, int k) {
	int c;
	char temp;
	if (k == 0) {
		for (int i = y; i < y + 2; i++) {
			c = 1;
			temp = board[0][i];
			for (int j = 1; j < n; j++) {
				if (board[j][i] == temp) c++;
				else {
					ans = max(c, ans);
					temp = board[j][i];
					c = 1;
				}
			}
		}
		ans = max(c, ans);
		c = 1;
		temp = board[x][0];
		for (int i = 1; i < n; i++) {
			if (board[x][i] == temp) c++;
			else {
				ans = max(c, ans);
				temp = board[x][i];
				c = 1;
			}
		}
		ans = max(c, ans);
	}
	else {
		for (int i = x; i < x + 2; i++) {
			c = 1;
			temp = board[i][0];
			for (int j = 1; j < n; j++) {
				if (board[i][j] == temp) c++;
				else {
					ans = max(c, ans);
					temp = board[i][j];
					c = 1;
				}
			}
		}
		ans = max(c, ans);
		c = 1;
		temp = board[0][y];
		for (int i = 1; i < n; i++) {
			if (board[i][y] == temp) c++;
			else {
				ans = max(c, ans);
				temp = board[i][y];
				c = 1;
			}
		}
		ans = max(c, ans);
	}
}

void init() {
	int c;
	char temp;
	for (int i = 0; i < n; i++) {
		c = 1;
		temp = board[i][0];
		for (int j = 1; j < n; j++) {
			if (board[i][j] == temp) c++;
			else {
				ans = max(c, ans);
				temp = board[i][j];
				c = 1;
			}
		}
		ans = max(c, ans);
	}

	for (int i = 0; i < n; i++) {
		c = 1;
		temp = board[0][i];
		for (int j = 1; j < n; j++) {
			if (board[j][i] == temp) c++;
			else {
				ans = max(c, ans);
				temp = board[j][i];
				c = 1;
			}
		}
		ans = max(c, ans);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < n; j++) board[i][j] = getchar();
	}

	init();

	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 2; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= n || ny >= n || board[i][j] == board[nx][ny]) continue;
				char temp = board[i][j];
				board[i][j] = board[nx][ny];
				board[nx][ny] = temp;

				candy(i, j, k);

				board[nx][ny] = board[i][j];
				board[i][j] = temp;
			}
	printf("%d", ans);
}


/*
#include <iostream>
#include <algorithm>
using namespace std;

int n;
char board[50][50];
int ans = 1;
int dx[] = { 0,1 };
int dy[] = { 1,0 };


void candy(int x, int y) {
	int c;
	char temp;
	for (int i = 0; i < n; i++) {
		if (abs(x - i) > 1 && abs(y - i) > 1) continue;
		c = 1;
		temp = board[i][0];
		for (int j = 1; j < n; j++) {
			if (board[i][j] == temp) c++;
			else {
				ans = max(c, ans);
				temp = board[i][j];
				c = 1;
			}
		}
		ans = max(c, ans);
	}

	for (int i = 0; i < n; i++) {
		if (abs(x - i) > 1 && abs(y - i) > 1) continue;
		c = 1;
		temp = board[0][i];
		for (int j = 1; j < n; j++) {
			if (board[j][i] == temp) c++;
			else {
				ans = max(c, ans);
				temp = board[j][i];
				c = 1;
			}
		}
		ans = max(c, ans);
	}
}

void swap(int a, int b, int c, int d) {
	char temp = board[a][b];
	board[a][b] = board[c][d];
	board[c][d] = temp;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < n; j++) board[i][j] = getchar();
	}

	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 2; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= n || ny >= n || board[i][j] == board[nx][ny]) continue;
				swap(i, j, nx, ny);
				candy(i, j);
				swap(i, j, nx, ny);
			}
	printf("%d", ans);
}


*/