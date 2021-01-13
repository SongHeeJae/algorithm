#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, m, d, map[15][15], playMap[15][15], ans = -1;
vector<int> archerPos; // 궁수 배치도

void copyMap() { // 기존 맵 복사
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			playMap[i][j] = map[i][j];
}

int getDist(int x1, int y1, int x2, int y2) { // 거리 계산
	return abs(x1 - x2) + abs(y1 - y2);
}

int attack() {
	int c = 0;
	vector<pair<int, int>> target; // 죽일 적
	for (int i = 0; i < 3; i++) {
		int pos = archerPos[i], x, y, minDist = INF;
		for (int j = 0; j < m; j++) {
			for (int k = n-1; k >= n-d; k--) {
				if (playMap[k][j] == 1) {
					int dist = getDist(k, j, n, pos);
					if (dist <= d && dist < minDist) {
						minDist = dist;
						x = k;
						y = j;
					}
				}
			}
		}
		if (minDist != INF)
			target.push_back({ x, y });
	}
	for (int i = 0; i < target.size(); i++) {
		int tx = target[i].first;
		int ty = target[i].second;
		if (playMap[tx][ty] == 1) c++; // 죽인 적 수 중복 방지
		playMap[tx][ty] = 0;
	}
	return c;
}

bool moveDown() { // 아래로 한칸 전진
	bool isFinished = false;
	for (int i = 0; i < m; i++) {
		for (int j = n - 1; j>0 ;j--) {
			playMap[j][i] = playMap[j-1][i];
			if (playMap[j][i] == 1) isFinished = true;
		}
		playMap[0][i] = 0;
	}
	return isFinished;
}

void play() { // 게임 수행
	int cnt = 0;
	copyMap();
	while (1) { // 더 이상 적이 없을 때까지 게임 반복
		cnt += attack();
		if (moveDown() == false) break;
	}
	ans = max(ans, cnt);
}

void selectArcher(int idx, int c) { // 가능한 궁수 배치도 조합
	if (c == 3) {
		play();
		return;
	}
	for (int i = idx; i < m; i++) {
		archerPos.push_back(i);
		selectArcher(i + 1, c + 1);
		archerPos.pop_back();
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j ++) scanf("%d", &map[i][j]);
	selectArcher(0, 0);
	printf("%d", ans);
}

/*
먼저 가능한 궁수의 배치도를 조합해냅니다.

그 뒤, 공격 가능한 적의 위치를 판별하여 죽인 적 수만큼 카운트를 세주며, 적을 전진시켜줬습니다.

타겟이 일치한다면, 궁수가 동일한 적에게 화살을 쏠 수도 있었기때문에, 죽인 적 수의 중복을 방지해주었습니다. 

가장 왼쪽 적에게 우선순위가 있기 때문에, 반복문은 아래행에서 왼쪽열 방향부터 수행했습니다. 
*/