#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	priority_queue<pair<int, int>> pq;
	int t, n, a, b, res, mb;
	scanf("%d", &t);
	while (t-- && scanf("%d", &n)) {
		res = 0;
		for (int i = 0; i < n && scanf("%d %d", &a, &b);i++)
			pq.push({ -a, b });
		mb = pq.top().second;
		while (!pq.empty()) {
			b = pq.top().second; pq.pop();
			if (mb < b) res++;
			mb = min(b, mb);
		}
		printf("%d\n", n - res);
	}
}

/*
먼저 서류심사 성적으로 비교하는 최소 힙에 담아줍니다.
요소를 하나씩 꺼내면, 서류심사는 어차피 밀리고 있으므로, 면접시험 성적만 비교해주면 됩니다.
면접시험 성적마저 앞에 꺼내진 요소들의 최소값에 밀린다면, 두 성적이 앞에 꺼내진 사람보다 떨어지는 것이므로 탈락합니다.
*/