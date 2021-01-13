#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, a;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	scanf("%d", &n);

	while (n--) {
		scanf("%d", &a);
		if (a == 0) {
			if (pq.empty()) printf("0\n");
			else {
				printf("%d\n", pq.top().second);
				pq.pop();
			}
		}
		else pq.push(make_pair(abs(a), a));
	}
}