#include <iostream>
using namespace std;

int n, a, arr[40000], ans = 1;

int lowerBound(int s, int e, int val) {
	while (s < e) {
		int mid = (s + e) / 2;
		if (arr[mid] >= val) e = mid;
		else s = mid + 1;
	}
	return e;
}

int main() {
	scanf("%d %d", &n, &arr[0]);
	for (int i = 1; i < n; i++) {
		scanf("%d", &a);
		if (arr[ans - 1] < a) arr[ans++] = a;
		else arr[lowerBound(0, ans - 1, a)] = a;
	}
	printf("%d", ans);
}

/*
연결선이 꼬이지 않도록 가장 많이 연결하려면,
가장 긴 증가하는 부분 수열의 길이를 구해주면 됩니다.
이분 탐색을 이용하여 구해주었습니다.
*/