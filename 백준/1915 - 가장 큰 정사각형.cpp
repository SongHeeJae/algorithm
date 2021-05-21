#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
int arr[1000][1000];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			ans = max(ans, arr[i][j]);
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (arr[i][j] == 1) {
				if (arr[i - 1][j - 1] && arr[i][j - 1] && arr[i - 1][j]) {
					arr[i][j] = min({ arr[i - 1][j - 1], arr[i][j - 1], arr[i - 1][j] }) + 1;
					ans = max(ans, arr[i][j]);
				}
			}
		}
	}
	printf("%d", ans * ans);
}

/*
현재 위치의 왼, 위, 왼위 대각선이 1이라면, 현재 지점은 정사각형에 포함될 수 있습니다.

arr[i][j] = 세 지점 중 가장 작은 값 + 1로 현재 지점을 업데이트해줍니다.
*/