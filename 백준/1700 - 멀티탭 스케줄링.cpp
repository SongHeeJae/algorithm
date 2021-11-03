#include <iostream>
#include <queue>
#include <set>
using namespace std;
#define MAX 100
#define INF 2147483647

int n, k, item[MAX], ans = 0;
queue<int> pos[MAX + 1]; // q[i] = i번 물건의 사용 위치
set<int> plugged;

void popIfNotEmpty(queue<int>& q) {
	if (!q.empty()) q.pop();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> item[i];
		if (plugged.size() < n)
			plugged.insert(item[i]);
		pos[item[i]].push(i);
	}

	for (int i = 0; i < k; i++) {
		auto find = plugged.find(item[i]);
		if (find == plugged.end()) {
			int laterItem = -1, laterIdx = -1;
			for (int it : plugged) {
				int idx = pos[it].empty() ? INF : pos[it].front();
				if (idx > laterIdx) {
					laterItem = it;
					laterIdx = idx;
				}
			}
			plugged.erase(laterItem);
			plugged.insert(item[i]);
			ans++;
		}
		popIfNotEmpty(pos[item[i]]);
	}
	cout << ans;
}

/*
현재 멀티탭에 꽂혀있는 전기용품 중에서, 미래에 처음 사용되는 시점이 가장 마지막 것을 교체하면, 플러그를 빼는 최소의 횟수를 구할 수 있습니다.
먼저 각 전기용품 별로 등장하는 시점을 큐에 기억해줍니다.
그리고 플러그에 꽂혀 있는 전기용품을 트리에 기억해두고,
새롭게 사용해야하는 전기용품이 아직 꽂혀있지 않다면,
꽂혀 있는 전기용품 중에서 가장 마지막에 처음 사용되는 물건을 찾아서 트리에 교체해주었습니다.
*/