#include <iostream>
#include <algorithm>
using namespace std;

int n, x, a[100000], c = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &x);
	sort(a, a + n);
	int l = 0, r = n - 1;
	while (l < r) {
		if (a[l] + a[r] == x) l++, r--, c++;
		else if (a[l] + a[r] < x) l++;
		else r--;
	}
	printf("%d", c);
}

/*
주어진 수들을 정렬해준 뒤, 시작과 끝을 가리키는 두 개의 인덱스를 선언해줍니다.
두 인덱스가 가리키는 수의 합이 x라면, 두 인덱스 모두 범위를 좁혀줍니다.
두 인덱스가 가리키는 수의 합이 x 미만이라면, 합을 높이기 위해 시작 인덱스를 하나 올려줍니다.
두 인덱스가 가리키는 수의 합이 x 초과라면, 합을 낮추기 위해 끝 인덱스를 하나 내려줍니다.
*/