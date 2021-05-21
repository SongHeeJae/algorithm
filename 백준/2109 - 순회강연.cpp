#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, p, d, s = 0;
pair<int, int> arr[10000];
priority_queue<int> pq;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].second, &arr[i].first);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (arr[i].first > pq.size()) {
			s += arr[i].second;
			pq.push(-arr[i].second);
		}
		else {
			if (-pq.top() < arr[i].second) {
				s += pq.top() + arr[i].second;
				pq.pop();
				pq.push(-arr[i].second);
			}
		}
	}
	printf("%d", s);
}

/*
먼저 날짜를 기준으로 오름차순 정렬해줍니다.

최소 힙에는 선택한 강연료를 기억해줄 것입니다.

최소 힙의 크기가 현재 검사하고 있는 d 미만이라면, 그 강연을 하면 됩니다.

최소 힙의 크기가 현재 검사하고 있는 d 이상이라면, 현재 검사하고 있는 p가 최소 힙의 top보다 큰 값일 경우에 지금 강연으로 교체하면 됩니다.
*/