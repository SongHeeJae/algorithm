#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, k, s;
	scanf("%d %d", &n, &k);

	if (n >= k) {
		printf("%d\n", n - k);
		return 0;
	}

	queue<int> q;
	vector<int> visited(100001, 0);
	visited[n] = true;
	q.push(n);

	while (!q.empty()) {
		s = q.front();
		q.pop();
		if (s == k) break;
		if (s < 99998 && !visited[s + 1]) {
			visited[s + 1] = visited[s] + 1;
			q.push(s + 1);
		}
		if (s > 0 && !visited[s - 1]) {
			visited[s - 1] = visited[s] + 1;
			q.push(s - 1);
		}
		if (s * 2 < 100001 && !visited[s * 2]) {
			visited[s * 2] = visited[s] + 1;
			q.push(s * 2);
		}
	}

	printf("%d\n", visited[s] - 1);

}
