#include <iostream>
#include <algorithm>
using namespace std;

int h, w, arr[500], ans = 0;

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < w; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < w; i++) {
		int left = 0, right = 0;
		for (int j = i - 1; j >= 0; j--) {
			left = max(arr[j], left);
		}
		for (int j = i + 1; j < w; j++) {
			right = max(arr[j], right);
		}
		int res = min(left, right) - arr[i];
		if (res > 0) ans += res;
	}
	printf("%d", ans);
}

/*
각 가로 지점마다 (좌우의 최고 높이 중 더 낮은 높이) - (현재 높이)와의 차이가 현재 지점에서 고이는 빗물의 양입니다.

아래와 같은 방법으로도 풀 수 있었습니다.
각 높이 별로 가로 지점을 검사하면서, 좌우가 막혀있는 칸들의 개수를 구해주었습니다.

#include <iostream>
using namespace std;

int h, w, arr[500], ans = 0;

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < w; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i <= h; i++) {
		int t = -1;
		for (int j = 0; j < w; j++) {
			if (arr[j] > i) {
				if (t == -1) {
					t = j;
				}
				else {
					ans += j - t - 1;
					t = j;
				}
			}
		}
	}
	printf("%d", ans);
}
*/