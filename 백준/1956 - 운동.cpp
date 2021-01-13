#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int main() {
	int v, e, a, b, c;
	scanf("%d %d", &v, &e);

	vector<vector<int>> d(v + 1, vector<int>(v+1, INF));
	while (e--) {
		scanf("%d %d %d", &a, &b, &c);
		d[a][b] = c;
	}

	for (int i = 1; i <= v; i++) d[i][i] = 0;

	// 거치는 정점
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			for (int k = 1; k <= v; k++)
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);

	int ans = INF;
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			if (i != j) ans = min(ans, d[i][j] + d[j][i]);
	printf("%d\n", ans != INF ? ans : -1);
}