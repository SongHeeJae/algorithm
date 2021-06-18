#include <iostream>
#include <algorithm>
#define INF 2147483647
using namespace std;

int n, m, arr[5000], l = INF, r = -INF;

bool isPossible(int val) {
	int cnt = 1, minVal = INF, maxVal = -INF;
	for (int i = 0; i < n; i++) {
		minVal = min(minVal, arr[i]);
		maxVal = max(maxVal, arr[i]);
		if(maxVal - minVal > val) { // 구간의 점수가 val보다 크다면 새로운 구간
			minVal = maxVal = arr[i];
			cnt++;
		}
	}
	return cnt <= m;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		l = min(arr[i], l);
		r = max(arr[i], r);
	}
	r = r - l;
	l = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (isPossible(mid)) r = mid - 1;
		else l = mid + 1;
	}
	printf("%d", l);
}

/*
이분 탐색을 이용하여 풀었습니다.
구간 점수의 최댓값이 mid일 때, 배열의 구간을 m개 이하로 나눌 수 있다면, 범위를 좁혀주면서 최솟값을 찾아줍니다.
*/