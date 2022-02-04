#include <iostream>
#include <algorithm>
#define MAX 8
using namespace std;

int n, s[MAX], w[MAX], ans = 0;

void breakEggs(int idx, int cnt) {
	ans = max(ans, cnt);
	if (idx == n) return;
	if (s[idx] <= 0) breakEggs(idx + 1, cnt);
	else {
		for (int i = 0; i < n; i++) {
			if (s[i] <= 0 || idx == i) continue;
			s[idx] -= w[i];
			s[i] -= w[idx];
			breakEggs(idx + 1, cnt + (s[idx] <= 0) + (s[i] <= 0));
			s[i] += w[idx];
			s[idx] += w[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> w[i];
	}

	breakEggs(0, 0);
	cout << ans;
}

/*
왼쪽 계란부터 아직 안깨진 계란과 부딪치게 하면서 최대로 깨뜨릴 수 있는 계란의 수를 구해주었습니다.
*/