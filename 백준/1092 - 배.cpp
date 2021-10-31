#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_CRANE 1000000
#define MAX_BOX 10000
using namespace std;

int n, m;
int crane[MAX_CRANE], pos[MAX_CRANE], box[MAX_BOX];
bool finished[MAX_BOX] = { false };

int findFinished(int bPos) {
	for (int i = bPos; i < m; i++)
		if (!finished[i]) return i;
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(pos, -1, sizeof(pos));

	cin >> n;
	for (int i = 0; i < n; i++) cin >> crane[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> box[i];

	sort(crane, crane + n, greater<>());
	sort(box, box + m, greater<>());

	if (box[0] > crane[0]) {
		cout << -1;
		return 0;
	}

	for (int i = 0, j = 0; i < m && j < n; i++)
		if (box[i] <= crane[j]) pos[j++] = i;

	int t = 0, c = 0;
	while (c != m) {
		for (int i = 0; i < n; i++) {
			if (pos[i] == -1) continue;
			pos[i] = findFinished(pos[i]);
			if (pos[i] != -1) {
				finished[pos[i]] = true;
				if (++c == m) break;
			}
		}
		t++;
	}
	cout << t;
}

/*
크레인의 무게 제한과 박스의 무게를 각각 내림차순 정렬해줍니다.
각 크레인은 자신이 옮길 수 있는 가장 무거운 박스부터 차례차례 옮겨주면, 최소 시간을 달성할 수 있습니다.
이를 위해, 각 크레인이 박스를 옮길 수 있는 시작점을 구해주었습니다.

예를 들어, 
크레인 = [32, 28, 25, 23]
박스 = [32, 27, 24, 20, 18, 16, 10, 7, 5, 2] 가 있을 때,
각 크레인이 박스를 옮길 수 있는 시작점은 [0, 1, 2, 3]이 됩니다.
모든 크레인이 한 사이클 박스를 옮길 때마다 시간은 1분씩 증가됩니다.
크레인은 박스를 하나 옮길 때마다, 다음으로 옮길 박스의 시작점을 업데이트해줍니다.
하지만 업데이트된 옮길 박스의 시작점은, 이미 다른 크레인에 의해 옮겨진 상태일 수도 있습니다.
그렇다면, 그 다음 박스를 계속해서 탐색하며 아직 안옮겨진 새로운 박스를 구해줍니다.
*/