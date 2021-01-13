#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int f, s, g, u, d;
	queue<pair<int, int>> q;
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	vector<int> visited(f + 1, false);
	visited[s] = true;
	q.push({s, 0});
	while(!q.empty()) {
		int x1 = q.front().first;
		int x2 = q.front().second;
		q.pop();
		if (x1 == g) {
			printf("%d\n", x2);
			return 0;
		}
		if (x1 + u <= f && !visited[x1 + u]) {
			q.push({ x1 + u, x2 + 1 });
			visited[x1 + u] = true;
		}
		if (x1 - d >= 1 && !visited[x1 - d]) {
			q.push({ x1 - d, x2 + 1 });
			visited[x1 - d] = true;
		}
	}
	printf("use the stairs\n");

}