#include <iostream>
#include <algorithm>
#include <cmath>
#define INF 2147483647
using namespace std;
int arr[100001], n, diff = INF, al, ar;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int l = 0, r = n - 1;
	while (l < r) {
		int val = arr[l] + arr[r];
		if (diff > abs(val)) {
			diff = abs(val);
			al = l, ar = r;
		}
		if (val > 0) r--;
		else l++;
	}
	printf("%d %d", arr[al], arr[ar]);
} 

/*
용액의 특성 값을 정렬해준 뒤, 배열의 시작과 끝을 가리키는 두 개의 인덱스를 둡니다.
두 인덱스는 두 용액의 특성 합이 0에 가까워지는 방향으로 움직이게 됩니다.
두 인덱스 용액의 특성 합이 0보다 크다면, 합을 줄여줘야하므로 끝 인덱스를 하나 내려줍니다.
두 인덱스 용액의 특성 합이 0보다 크지 않다면, 합을 올려줘야하므로 시작 인덱스를 하나 올려줍니다.
이 과정 속에서, 두 용액의 특성합이 최소가 되는 시점을 기억해줍니다.
*/