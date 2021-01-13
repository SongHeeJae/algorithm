#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, a;
	scanf("%d", &n);
	vector<vector<int>> p(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d", &p[i][j]);

	vector<vector<int>> s(n, vector<int>(n, 0));
	s[0][0] = p[0][0];
	int maxValue = -1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) s[i][j] = s[i - 1][j] + p[i][j];
			else if (j == i) s[i][j] = s[i - 1][j - 1] + p[i][j];
			else s[i][j] = max(s[i - 1][j - 1], s[i - 1][j]) + p[i][j];
			maxValue = s[i][j] > maxValue ? s[i][j] : maxValue;
		}
	}

	printf("%d\n", maxValue);


}