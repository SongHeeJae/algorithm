#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector<vector<int>> graph(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for (int k = 0; k < n; k++)
				if (graph[j][i] && graph[i][k])
					graph[j][k] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) printf("%d ", graph[i][j]);
		printf("\n");
	}
}