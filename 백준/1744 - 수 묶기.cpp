#include <iostream>
#include <algorithm>

int n, ans = 0, l, r, arr[10000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	std::sort(arr, arr + n);
	for (l = 0; l < n - 1 && arr[l + 1] < 1; l += 2)
		ans += arr[l] * arr[l + 1];
	for (r = n - 1; r > 0 && arr[r - 1] > 1; r -= 2)
		ans += arr[r] * arr[r - 1];
	while (l <= r) ans += arr[l++];
	printf("%d", ans);
} 

/*
두 수를 묶었을 때의 곱을 최대화하기 위해 수를 정렬해줍니다.
가장 큰 두 개의 양수를 묶거나, 가장 작은 두 개의 음수를 묶으면, 두 수를 더한 것보다 더 큰 수를 구할 수 있습니다.
음수는 0과 묶였을 때, 그 값이 0이 되므로 합을 최대화할 수 있습니다.
1인 두 수는, 두 수를 묶는 것보다 그냥 두 수를 더하는 것이 더욱 합을 최대화할 수 있습니다. 
*/