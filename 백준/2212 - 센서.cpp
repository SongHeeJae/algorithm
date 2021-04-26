#include <iostream>
#include <algorithm>
int n, k, s = 0, arr[10001];
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	std::sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++)
		s += arr[i] = arr[i + 1] - arr[i];
	std::sort(arr, arr + n - 1);
	for (int i = n - 2; i >= 0 && --k; i--) s -= arr[i];
	printf("%d", s);
}

/*
문제 예시를 기준으로 하면,
센서의 좌표를 오름차순으로 정렬하면 [1, 3, 6, 6, 7, 9] 입니다.
각 센서 사이의 거리는 [2, 3, 0, 1, 2] 입니다.
k == 2이므로 두 그룹으로 묶어줄 수 있으니, 각 거리 사이를 k - 1번 건너뛸 수 있습니다.
따라서, 센서 사이의 거리에서 k - 1개까지의 최댓값을 제외한 거리 합을 구해주면 됩니다.
*/