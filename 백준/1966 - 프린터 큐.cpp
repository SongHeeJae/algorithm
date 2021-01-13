#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int t, n, m, a, f;
	scanf("%d", &t);
	while (t--) {
		int c = 0;
		scanf("%d %d", &n, &m);
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			f = m == i ? 1 : 0;
			q.push({a, f});
			pq.push(a);
		}

		while (1) {
			pair<int, int> q_val = q.front();
			int pq_val = pq.top();
			q.pop();
			if (q_val.first < pq_val)
				q.push(q_val);
			else {
				pq.pop();
				c++;
				if (q_val.second) break;
			}
		}
		printf("%d\n", c);
	}
}