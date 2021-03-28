#include <algorithm>
#include <iostream>
int m, n, l, ans = 0, x, y, shot[100001];
int main() {
	scanf("%d %d %d", &m, &n, &l);
	for (int i = 0; i < m && scanf("%d", &shot[i]); i++);
	std::sort(shot, shot + m);
	for (int i = 0; i < n && scanf("%d %d", &x, &y); i++) {
		int val = l - y, s = 0, e = m;
		if (val < 0) continue;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (shot[mid] < x - val) s = mid + 1;
			else if (shot[mid] > x + val) e = mid - 1;
			else {
				ans++;
				break;
			}
		}
	}
	printf("%d", ans);
}

/*
각 동물이 사냥당할 수 있는 범위인지 구해주었습니다.
동물의 좌표가 x, y라면,
l - y > 0 일 때, (x - (l-y)) ~ (x + (l-y)) 범위 내에 사로가 속해있다면 사냥이 가능합니다.
범위 내에 사로가 속해있는지를 이분 탐색을 통하여 구해주었습니다.
*/
