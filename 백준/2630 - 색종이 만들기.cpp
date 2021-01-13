#include <iostream>
#include <vector>
using namespace std;

int white = 0, blue = 0;

void square(vector<vector<int>>& paper, int x, int y, int w) {

	bool zero = true, one = true;
	for (int i = x; i <= x + w; i++)
		for (int j = y; j <= y + w; j++)
			if (paper[i][j]) zero=false;
			else one=false;

	if (zero) white++;
	else if (one) blue++;
	else {
		square(paper, x, y, w / 2);
		square(paper, x + (w / 2) + 1, y, w / 2);
		square(paper, x, y + (w / 2) + 1, w / 2);
		square(paper, x + (w / 2) + 1, y + (w / 2) + 1, w / 2);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> paper(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &paper[i][j]);
	square(paper, 0, 0, n - 1);
	printf("%d\n%d\n", white, blue);
}