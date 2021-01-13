#include <iostream>
#include <queue>
using namespace std;
int main()
{
	priority_queue<pair<int, int>> pq;
	priority_queue<int, vector<int>, greater<int>> pq2;
	int i, a, s = 0;
	for (i = 1; i <= 8 && scanf("%d", &a);) pq.push({ a, i++ });
	for (i = 5; i--; pq.pop()) {
		s += pq.top().first;
		pq2.push(pq.top().second);
	}
	printf("%d\n", s);
	for (; !pq2.empty(); pq2.pop())printf("%d ", pq2.top());
}