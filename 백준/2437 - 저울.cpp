#include <iostream>
#include <cmath>
#include <algorithm>

int n, s = 1;
int arr[1000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	std::sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (s < arr[i]) break;
		s += arr[i];
	}
	printf("%d", s);
}

/*
시간 내에 들어오려면 그리디로 풀어야하는데, 어떻게 풀어야할지 감이 오지 않았습니다.
그래서 풀이를 참고하였습니다.

먼저, 각 추를 오름차순으로 정렬합니다. 저울에 순서대로 올려나간다고 생각했습니다.
지금 올린 추의 무게와 누적합을 비교합니다.
누적합이 지금 추의 무게보다 작다면, 지금까지의 누적합이 측정할 수 없는 양의 정수 무게의 최솟값 입니다.
그렇지 않다면, 추를 하나 더 올리며 누적합을 업데이트합니다.
*/