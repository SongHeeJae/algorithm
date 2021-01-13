#include <cstdio>
#include <cmath>
int NS[4][8], k, left[4] = {6,6,6,6}, n, m, s = 0;
void rotate(int a, int b, int c) { // a == 톱니바퀴번호, b == 회전 방향, c == 지나온 이전 톱니바퀴번호
	if (a > 0 && a - 1 != c && NS[a - 1][(left[a - 1] + 4) % 8] != NS[a][left[a]])
		rotate(a - 1, -1 * b, a); // 왼쪽 톱니바퀴 검사 후 회전
	if (a < 3 && a + 1 != c && NS[a + 1][left[a + 1]] != NS[a][(left[a] + 4) % 8])
		rotate(a + 1, -1 * b, a); // 오른쪽 톱니바퀴 검사 후 회전
    // 모든 회전이 끝났으면 상태 업데이트
	left[a] = b == 1 ? (left[a] + 7) % 8 : (left[a] + 1) % 8;
}
int main() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++) scanf("%1d", &NS[i][j]);
	scanf("%d", &k);
	while (k-- && scanf("%d %d", &n, &m))
		rotate(n-1, m, n-1);
	for (int i = 0; i < 4; i++)
		s += NS[i][(left[i] + 2) % 8] ? pow(2, i) : 0;
	printf("%d", s);
}

/*

재귀를 이용하여 각 바퀴들을 회전시켰습니다.

각 톱니바퀴의 가장 왼쪽 톱니의 위치를 기준으로 잡아서 회전해주며 업데이트해줬습니다.

간과했던 점은, 톱니는 동시에 돌아가는데, 각각 하나씩 회전하며 전파되는걸로 생각해서 오류가 났었습니다.

그 부분을, 회전이 동시에 끝난 뒤 상태가 업데이트가 되는 것으로 수정하여 해결하였습니다.

*/