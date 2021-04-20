#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int t, n, x, y, r, p[5001];
vector<vector<int>> arr;

int findParent(int x) {
	if (p[x] == x) return x;
	else return p[x] = findParent(p[x]);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		arr.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &r);
			arr.push_back({ x, y, r });
			p[i] = i;
		}
		int cnt = 0;
		for (int i = 0; i < arr.size(); i++) {
			int ix = arr[i][0];
			int iy = arr[i][1];
			int ir = arr[i][2];
			for (int j = i + 1; j < arr.size(); j++) {
				int jx = arr[j][0];
				int jy = arr[j][1];
				int jr = arr[j][2];
				int dx = ix - jx;
				int dy = iy - jy;
				int dr = ir + jr;
				if (dx * dx + dy * dy <= dr * dr) {
					int pi = findParent(i);
					int pj = findParent(j);
					if (pi != pj) {
						p[pi] = pj;
						cnt++;
					}
				}
			}
		}
		printf("%d\n", n - cnt);
	}
}

/*
각 통신탑들이 같은 영역에 포함되어 있는지 구한 뒤, 같은 영역에 속해있다면 같은 그룹으로 묶어주었습니다.
거리 R 내에 포함되는 통신 영역의 범위 기준이 모호했는데, 좌표 평면에서 두 점 사이의 거리를 계산한 것으로 기준을 잡으면 되었습니다. 
*/