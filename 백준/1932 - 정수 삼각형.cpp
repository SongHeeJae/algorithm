#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[501][501] = { 0 }, ans = 0;

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		ans = max(ans, arr[n][i]);
	}
	printf("%d", ans);
}

/*
arr[i][j] = i행 j열까지 내려왔을 때의 최댓값을 저장해줍니다.

각 행에서 가장 왼쪽 값은, 바로 상위 행에서 가장 왼쪽 경로를 통해서만 내려올 수 있습니다.
  -> arr[i][j] += arr[i-1][j];

각 행에서 가장 오른쪽 값은, 바로 상위 행에서 가장 오른쪽 경로를 통해서만 내려올 수 있습니다.
  -> arr[i][j] += arr[i-1][j-1];

그 외의 값은, 바로 상위 행에서 왼쪽 경로와 오른쪽 경로를 통해서 내려올 수 있습니다.
  -> arr[i][j] += max(arr[i-1][j], arr[i-1][j-1]);
*/