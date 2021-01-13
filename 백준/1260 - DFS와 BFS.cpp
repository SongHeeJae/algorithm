#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

void DFS(bool *visit, std::vector<int> *d, int start)
{
	printf("%d ", start);
	visit[start] = true;
	for (int i = 0; i < d[start].size(); i++)
		if (!visit[d[start][i]]) DFS(visit, d, d[start][i]);
}

void BFS(bool* visit, std::vector<int> *d, int start)
{
	std::queue<int> q;
	int s;
	visit[start] = true;
	q.push(start);
	printf("%d ", start);
	while (!q.empty())
	{
		s = q.front();
		q.pop();
		for (int i = 0; i < d[s].size(); i++)
		{
			if (!visit[d[s][i]])
			{
				q.push(d[s][i]);
				visit[d[s][i]] = true;
				printf("%d ", d[s][i]);
			}
		}
	}
}

int main()
{
	int n, m, v;
	int x, y;
	bool* visit;
	scanf("%d %d %d", &n, &m, &v);
	visit = new bool[n + 1];
	memset(visit, false, sizeof(bool) * (n + 1));

	std::vector<int>* d = new std::vector<int>[n+1];

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		d[x].push_back(y);
		d[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
	{
		std::sort(d[i].begin(), d[i].end());
	}

	DFS(visit, d, v);

	printf("\n");
	memset(visit, false, sizeof(bool) * (n + 1));

	BFS(visit, d, v);

	delete[] d;
}

