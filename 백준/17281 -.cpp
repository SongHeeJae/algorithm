#include <iostream>
#include <algorithm>
using namespace std;
int n, a[50][9], b[9] = { 0 }, v[9] = { 1 }, ans = 0;
// b[3] = 0 (1번 선수는 4번타자), v[0] = 1 (1번 타자는 이미 채워짐)
void play() {
	int turn = 0, c = 0;
	for (int i = 0; i < n; i++) {
		int p[3] = { 0 }, out = 0;
		while (1) {
			int res = a[i][b[turn]]; // 결과
			if (res == 0) out++; // 아웃
			else if (res == 1) {  // 1루
				c += p[2];
				p[2] = p[1];
				p[1] = p[0];
				p[0] = 1;
			}
			else if (res == 2) { // 2루
				c += p[1] + p[2];
				p[2] = p[0];
				p[1] = 1;
				p[0] = 0;
			}
			else if (res == 3) { // 3루
				c += p[0] + p[1] + p[2];
				p[0] = p[1] = 0;
				p[2] = 1;
			}
			else { // 홈런
				c += p[0] + p[1] + p[2] + 1;
				p[0] = p[1] = p[2] = 0;
			}
			turn = (turn + 1) % 9; // 타자 순회
			if (out == 3) break;
		}
	}
	ans = max(ans, c);
}

void order(int c) { // 순서 만들어냄
	if (c == 9) play(); // 모든 순서 만들어졌으면 게임 시작
	else if (c == 3) order(c + 1); // 4번 타자는 1번 선수로 이미 채워져있으므로 넘어감
	else {
		for (int i = 0; i < 9; i++) {
			if (v[i]) continue;
			v[i] = 1;
			b[c] = i;
			order(c + 1);
			v[i] = 0;
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 9; j++) scanf("%d", &a[i][j]);
	order(0);
	printf("%d", ans);
}

/*
먼저 가능한 모든 타순을 만들어냅니다. 이 때, 1번 선수는 4번 타자로 고정입니다.

그리고 그 가능한 순서로 게임을 돌려보고, 구해진 점수로 최댓값을 업데이트 해줍니다.

처음에는 각 이닝마다 상이한 타순이 만들어지는 줄 알고 어떻게 시간 안에 들어오나했는데,

모든 이닝에 동일한 타순을 적용하면 되는 것이었습니다. 
*/