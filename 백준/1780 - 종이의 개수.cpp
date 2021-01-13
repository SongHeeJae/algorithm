#include <iostream>
#include <vector>
using namespace std;
int a = 0, b = 0, c = 0;
void square(vector<vector<int>>& paper, int x, int y, int w) {
	bool aa = true, bb = true, cc = true;
	for (int i = x; i < x + w; i++)
		for (int j = y; j < y + w; j++) {
			if (paper[i][j] != -1) aa = false;
			if (paper[i][j] != 0) bb = false;
			if (paper[i][j] != 1) cc = false;
		}

	if (aa) a++;
	else if (bb) b++;
	else if (cc) c++;
	else {
		square(paper, x, y, w / 3);
		square(paper, x, y + w / 3, w / 3);
		square(paper, x, y + w / 3 * 2, w / 3);
		square(paper, x + w / 3, y, w / 3);
		square(paper, x + w / 3, y + w / 3, w / 3);
		square(paper, x + w / 3, y + w / 3 * 2, w / 3);
		square(paper, x + w / 3 * 2, y, w / 3);
		square(paper, x + w / 3 * 2, y + w / 3 , w / 3);
		square(paper, x + w / 3 * 2, y + w / 3 * 2, w / 3);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> paper(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &paper[i][j]);
	square(paper, 0, 0, n);
	printf("%d\n%d\n%d\n", a, b, c);
}