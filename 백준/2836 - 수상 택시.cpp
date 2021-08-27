#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m, s, e;
vector<pair<int, int>> arr;

bool comp(pair<int, int>& a, pair<int, int>& b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		if (e > s) continue;
		arr.push_back({ s, 1 });
		arr.push_back({ e, -1 });
	}

	sort(arr.begin(), arr.end(), comp);

	int p = -1;
	int cnt = 0;
	ll ans = 0;
	for (auto& a : arr) {
		cnt += a.second;
        if (a.second == -1 && p == -1) {
			p = a.first;
		} else if(cnt == 0) {
			ans += a.first - p;
			p = -1;
		}
	}
	cout << ans * 2 + m;
}

/*
출발 지점이 도착 지점보다 작다면, 그냥 가던 방향을 따라서 M번 집으로 진행하면 됩니다.
하지만 출발 지점이 도착 지점보다 크다면, 가던 방향을 역주행해서 도착 지점으로 데려다줘야합니다.
후자일 때, 출발 지점에는 1의 가중치, 도착 지점에는 -1의 가중치를 준 뒤, 지점에 따라 오름차순으로 정렬해줍니다.
가중치의 합을 계속 더해주면서, 합이 0이 되는 출발 지점에 도착했을 때, 처음으로 -1의 가중치(도착 지점)를 만났던 지점으로 역주행해줍니다.
역주행으로 도착 지점으로 사람들을 내려다준 뒤, 다시 원래의 지점으로 돌아가야하므로,
역주행했던 거리 * 2 + M이 이동해야하는 거리의 최솟값이 됩니다.
*/