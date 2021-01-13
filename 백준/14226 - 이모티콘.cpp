#include <iostream>
#include <queue>
using namespace std;
int main() {
	int s;
	bool v[1001][1001] = { false }; // 화면 이모티콘 x개에서 y개의 클립보드 상태 방문 여부
	scanf("%d", &s);
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 1, 0 }, 0});
	while (!q.empty()) {
		int n = q.front().first.first; // 개수
		int t = q.front().first.second; // 시간
		int c = q.front().second; // 클립보드
		q.pop();
		if (n == s) {
			printf("%d", t);
			break;
		}
		if (n != 0 && !v[n][n]) { // 1번. 클립보드에 복사할 갯수가 있고 아직 복사 안했을 경우.
			q.push({ { n, t + 1}, n });
			v[n][n] = true;
		}
		if (c != 0 && n + c < 1001 && !v[n + c][c]) { // 2번. 클립보드에 개수가 있을 경우.
			q.push({ { n + c, t + 1}, c });
			v[n + c][c] = true;
		}
		if (n > 1 && !v[n - 1][c]) { // 3번. 0개, 1개일 경우엔 굳이 안 지워도됨.
			q.push({ { n - 1, t + 1 }, c });
			v[n - 1][c] = true;
		}
	}
}

/*
화면에 입력된 이모티콘 개수가 x개이고, 이 때의 클립보드에 복사된 이모티콘 개수가 y개인 경우에는 중복해서 방문하지 않았습니다.
*/