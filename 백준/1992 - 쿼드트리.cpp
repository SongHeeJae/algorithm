#include <iostream>
#include <vector>
using namespace std;

void square(vector<vector<int>>& paper, int x, int y, int w) {
	bool zero = true, one = true;
	for (int i = x; i <= x + w; i++)
		for (int j = y; j <= y + w; j++)
			if (paper[i][j]) zero=false;
			else one=false;

	if (zero) printf("0");
	else if (one) printf("1");
	else {
		printf("(");
		square(paper, x, y, w / 2);
		square(paper, x, y + (w / 2) + 1, w / 2);
		square(paper, x + (w / 2) + 1, y, w / 2);
		square(paper, x + (w / 2) + 1, y + (w / 2) + 1, w / 2);
		printf(")");
	}
}

int main() {
	int n;
	char c;
	scanf("%d", &n);
	vector<vector<int>> paper(n, vector<int>(n));
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n && (c = getchar()); j++)
			paper[i][j] = c - '0';
		getchar();
	}
	square(paper, 0, 0, n - 1);
}