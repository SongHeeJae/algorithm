#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, a1, a2, a3;
int arr[5000];
long long diff = 1e11;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n - 2 && diff; i++) {
		int l = i + 1;
		int r = n - 1;
		while (l < r && diff) {
			long long s = (long long)arr[l] + arr[r] + arr[i];
			if (diff > abs(s)) {
				a1 = i;
				a2 = l;
				a3 = r;
				diff = abs(s);
			}
			if (s > 0) r--;
			else l++;
		}
	}
	printf("%d %d %d", arr[a1], arr[a2], arr[a3]);
}

/*
먼저 용액을 정렬해준 뒤, 기준 값을 하나 잡아줍니다.

기준 값을 제외한 나머지 용액에서 두 용액을 선택하며, 그 합의 절댓값이 최소가 되는 용액을 찾아줍니다
*/