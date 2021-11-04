#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 1001

int t, n, m, a, b;
vector<pair<int, int>> arr;
bool visit[MAX] = { false };

bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		arr.clear();
		memset(visit, false, sizeof(visit));

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			arr.push_back({ a, b });
		}

		sort(arr.begin(), arr.end(), comp);

		int cnt = 0;
		for (auto& it : arr) {
			for (int i = it.first; i <= it.second; i++) {
				if (!visit[i]) {
					visit[i] = true;
					cnt++;
					break;
				}
			}
		}
		cout << cnt << "\n";
	}
}

/*
b 오름차순, a 오름차순으로 정렬한 뒤,
낮은 번호의 책 먼저 할당해주면 최대 학생 수를 구할 수 있습니다.
*/