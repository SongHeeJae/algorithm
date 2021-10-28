#include <iostream>
#include <queue>
#define MAX 200000
using namespace std;

int n, m, h, b, ans = 0, a[MAX];
priority_queue<pair<int, int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	h = n * 24;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		ans += a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b;
		pq.push({ b, 100 - a[i] });
	}

	while (!pq.empty() && h > 0) {
		int bb = pq.top().first;
		int aa = pq.top().second;
		pq.pop();
		if (aa >= bb) {
			ans += bb;
			pq.push({ bb, aa - bb });
			h--;
		}
		else {
			pq.push({ aa, aa });
		}
	}
	cout << ans;
}

/*
우선순위 큐에 {시간 당 점수, 얻을 수 있는 남은 점수}를 넣어줍니다. (시간 당 점수 내림차순)
얻을 수 있는 남은 점수가 시간 당 점수보다 같거나 작다면, 지금의 1시간을 써서 가장 높은 점수를 취할 수 있는 과목이 됩니다.
따라서, 그 과목을 1시간 공부한 만큼 점수를 추가해줍니다. 그리고 얻을 수 있는 남은 점수를 업데이트하여 다시 우선순위 큐에 넣어줍니다.
얻을 수 있는 남은 점수가 시간 당 점수보다 크다면, 지금의 1시간을 썼을 때, 이것이 가장 높은 점수를 취할 수 있을지 확신할 수 없습니다. 따라서, 시간 당 점수를 현재 얻을 수 있는 남은 점수로 업데이트하여 다시 우선순위 큐에 넣어줍니다.
주어진 시간을 다 사용할 때까지 수행해줍니다.
*/