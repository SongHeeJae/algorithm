#include <iostream>
#include <queue>
using namespace std;
int n, a;
priority_queue<int> pq;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n * n; i++) {
		scanf("%d", &a);
		pq.push(-a);
		if (pq.size() > n) pq.pop();
	}
	printf("%d", -pq.top());
}
/*
최소 힙으로 N개의 수만 유지해주었습니다.
N개의 수를 초과하면, 그 때의 최솟값은 없애줍니다.
*/