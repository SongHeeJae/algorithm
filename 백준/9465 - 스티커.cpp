#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int t, n, a[2][100000];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);

		a[0][1] = max(a[0][0], a[0][1] + a[1][0]); // 두번째 열에 대해서는
		a[1][1] = max(a[1][0], a[0][0] + a[1][1]); // 직접 구해둠. 첫번째 열은 기존 입력값

		for (int i = 2; i < n; i++) {
			a[0][i] = max(a[1][i-1], a[1][i-2]) + a[0][i];
			a[1][i] = max(a[0][i-1], a[0][i-2]) + a[1][i];
		}
		printf("%d\n", max(a[0][n-1], a[1][n-1]));
	}
}

/*
2행 4열 크기의 스티커에 다음과 같이 번호를 붙여보겠습니다.

| 1 | 2 | 3 | 4 |
| 5 | 6 | 7 | 8 |

먼저 1열의 스티커에 대해서 보겠습니다.
만약 1번 스티커를 사용한다면, 대각선 방향으로 6번과 3번의 스티커를 사용하거나 7번의 스티커를 사용할 수 있습니다.
만약 5번 스티커를 사용한다면, 대각선 방향으로 2번과 7번의 스티커를 사용하거나 3번의 스티커를 사용할 수 있습니다.

즉, 대각선 방향으로 2열 연달아 스티커를 사용했던 경우와 대각선으로 2열 떨어진 스티커를 사용했을 때의 최댓값을 구해주면 됩니다.

a[0...1][i]는 i열에서 0 또는 1행의 스티커를 사용했을 때 나올 수 있는 최댓값입니다.
a[0][i] = max(a[1][i-1], a[1][i-2]) + a[0][i];
a[1][i] = max(a[0][i-1], a[0][i-2]) + a[1][i];

최종적으로 가장 끝열에서 각 행에 스티커를 붙였을 때 더욱 큰 값이 얻을 수 있는 최대 점수입니다.
*/