#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int main() {
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);

	vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		d[a][b] = min(d[a][b], c); // 이미 경로 있는 경우 최솟값
	}

	for (int i = 1; i <= n; i++)
		d[i][i] = 0;

	// 거치는 정점
	for(int i=1; i<= n; i++)
		// 출발
		for (int j=1; j<=n; j++)
			// 도착
			for (int k = 1; k <= n; k++)
				if (d[j][k] > d[j][i] + d[i][k])
					d[j][k] = d[j][i] + d[i][k];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", d[i][j] != INF ? d[i][j] : 0);
		printf("\n");
	}

}
