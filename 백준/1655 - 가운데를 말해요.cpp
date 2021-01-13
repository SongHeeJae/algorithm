#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, a;
	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;

	scanf("%d", &n);

	while (n--) {
		scanf("%d", &a);
		// max_pq의 크기가 min_pq와 같거나 1크다
		if (max_pq.size() > min_pq.size()) min_pq.push(a);
		else max_pq.push(a); // 초기에는 max_pq에 push
		// max_pq.top은 min_pq의 탑보다 작거나 같아야하므로 스왑
		if (!max_pq.empty() && !min_pq.empty() && max_pq.top() > min_pq.top()) {
			int a1 = max_pq.top();
			int a2 = min_pq.top();
			max_pq.pop();
			min_pq.pop();
			max_pq.push(a2);
			min_pq.push(a1);
		}
		printf("%d\n", max_pq.top());
	}
}