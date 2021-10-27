#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

int n, d, w, s = 0;
vector<pair<int, int>> dw;
bool finished[MAX] = { false };

bool comp(pair<int, int>& a, pair<int, int>& b) {
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		dw.push_back({ d, w });
	}
	sort(dw.begin(), dw.end(), comp);
	
	for (int i = 0; i < dw.size(); i++) {
		int day = dw[i].first;
		while (finished[day--]);
		if (day >= 0) {
			s += dw[i].second;
			finished[day + 1] = true;
		}
	}
	cout << s;
}

/*
과제 점수를 기준으로 내림차순 정렬하고, 미룰 수 있는 과제는 최대한 미뤄주었습니다.
예를 들어, 4일 남은 50점 과제와 4일 남은 40점 과제 두 개가 주어졌다고 가정해보겠습니다.
점수로 내림차순 정렬이 되어있기 때문에 50점 과제를 먼저 선택하게 됩니다.
이 과제를 수행해야 높은 점수를 수행할 수 있으므로, 4일 남은 50점 과제는 4일 차에 수행시킵니다.
다음으로, 4일 남은 40점 과제를 선택하게 됩니다.
이 과제는, 4일 차에는 이미 더 높은 점수의 과제가 선택되어있으므로 3일 이내에만 수행시킬 수 있으면 됩니다.
즉, 3일 이내에 수행해야할 과제가 없다면, 그날 수행시킵니다.
높은 점수의 과제를 최대한 나중으로 미뤄나가며 얻을 수 있는 최대 점수를 구해준 것입니다.
*/