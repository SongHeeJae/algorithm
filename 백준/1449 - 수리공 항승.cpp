#include <iostream>
#include <algorithm>
int n, l, arr[1000], ans = 1;
int main() {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	std::sort(arr, arr + n);
	for (int i = 1, c = arr[0]; i < n; i++)
		if (c + l <= arr[i])
			c = arr[i], ans++;
	printf("%d", ans);
} 

/*
물을 막으려면, 좌우 0.5 간격만큼 간격을 줘야합니다.
따라서 1, 3에서 파이프의 물이 샌다면, 길이가 2인 테이프 두개가 필요합니다.
파이프의 지점을 오름차순으로 정렬한 뒤, 길이가 L인 테이프를 붙였을 때 그 테이프가 물을 막아주는 지점까지 점프해줍니다.
기존에 붙인 테이프가 물을 막아주지 않는 지점에 도달하면, 새로운 테이프를 붙여줍니다.
*/