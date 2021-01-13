#include <iostream>
#include <deque>
using namespace std;

int main() {
	int n, m, a, idx, c = 0;
	deque<int> q;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) q.push_back(i);
	while (m--) {
		scanf("%d", &a);
		if (q.front() == a) q.pop_front();
		else {
			for (idx = 0; idx < q.size(); idx++)
				if (q[idx] == a) break;
			while (q.front() != a) {
				if (idx <= q.size() / 2) {
					q.push_back(q.front());
					q.pop_front();
				}
				else {
					q.push_front(q.back());
					q.pop_back();
				}
				c++;
			}
			q.pop_front();
		}
	}
	printf("%d", c);
}
