#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, l, a;
vector<int> arr;

int main() {
	scanf("%d %d %d", &n, &m, &l);
	arr.push_back(0);
	arr.push_back(l);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	int s = 1, e = l;
	while (s <= e) {
		int mid = (s + e) / 2;
		int cnt = 0;
		for (int i = 1; i < arr.size(); i++) {
			int dist = arr[i] - arr[i - 1];
			if (dist <= mid) continue;
			// 두 지점 사이의 거리 dist에 세울 수 있는 휴게소의 개수
			// dist % mid == 0이면 휴게소를 겹쳐서 세우는 것이므로 -1
			cnt += dist / mid - (dist % mid == 0);
		}
		if (cnt > m) s = mid + 1;
		else e = mid - 1;
	}
	printf("%d", e + 1);
}

/*
이분 탐색을 통해 해결하였습니다.
휴게소 사이의 거리가 mid일 때의 세울 수 있는 휴게소 개수를 구한 뒤,
그 개수가 m개를 초과한다면 휴게소 사이의 거리를 늘려서 그 개수를 줄여주고,
그 개수가 m개 이하라면 휴게소 사이의 거리를 줄여서 그 개수를 높여줍니다.
이를 통해 m개를 지을 수 있는 최소 mid 값을 구해주었습니다.
*/
