#include <cstdio>
#define INF 987654321
int graph[100][100];
int n, m, ans = 0, temp = INF, i, j;
int main() {
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) graph[i][j] = INF;
	while (m-- && scanf("%d %d", &i, &j))
		graph[i][j] = graph[--j][--i] = 1;
	for (i = 0; i < n; i++) graph[i][i] = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (m = 0; m < n; m++)
				if (graph[j][m] > graph[j][i] + graph[i][m])
					graph[j][m] = graph[j][i] + graph[i][m];
	for (i = 0; i < n; i++) {
		m = 0;
		for (j = 0; j < n; j++) m += graph[i][j];
		if (temp > m) {
			temp = m;
			ans = i;
		}
	}
	printf("%d", ++ans);
}