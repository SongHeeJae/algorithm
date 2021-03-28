#include <cstdio>
int arr[101], res[101], n, cnt = 1;

int lowerBound(int target) {
	int s = 0, e = cnt - 1;
	while (s < e) {
		int mid = (s + e) / 2;
		if (res[mid] >= target) e = mid;
		else s = mid + 1;
	}
	return e;
}

int main() {
	scanf("%d %d", &n, &arr[0]);
	res[0] = arr[0];
	for (int i = 1; i < n && scanf("%d", &arr[i]); i++) {
		if (arr[i] < res[cnt - 1]) res[lowerBound(arr[i])] = arr[i];
		else res[cnt++] = arr[i];
	}
	printf("%d", n - cnt);
}

/*
가장 긴 증가하는 부분 수열을 남기고, 나머지를 모두 제외하면 꼬인 전깃줄이 모두 제거됩니다.
[2 3 4 1]이 있을 때, 부분 수열의 개수를 구하기 위한 배열 arr 이 있다면,

arr - []
 - 2 : 비어있으므로 바로 삽입
arr - [2]
 - 3 : arr의 마지막 요소보다 큰 값이므로 바로 삽입
arr - [2, 3]
 - 4 : arr의 마지막 요소보다 큰 값이므로 바로 삽입
arr - [2, 3, 4]
 - 1 :  arr의 마지막 요소보다 작은 값이므로 lower bound로 1보다 큰 값이 시작되는 첫 위치로 대체
arr - [1, 3, 4]


따라서, arr의 길이가 가장 긴 증가하는 부분 수열의 길이가 됩니다.
n - (arr의 길이) == 제거해야할 전깃줄의 개수 입니다.
*/