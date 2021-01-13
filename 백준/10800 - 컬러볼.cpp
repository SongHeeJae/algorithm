#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b, s = 0;
vector<pair<int, pair<int, int>>> ball;
int ans[200000] = { 0, };
int col[200000] = { 0, };
int wei[2001] = { 0, };

bool cmp1(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	return a.second.second != b.second.second 
		? a.second.second < b.second.second : a.second.first < b.second.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ball.push_back({ {i}, {a - 1, b} });
	}

	sort(ball.begin(), ball.end(), cmp1);

	int s = 0;
	for (int i = 0; i < n; i++) {
		int idx = ball[i].first;
		int c = ball[i].second.first;
		int w = ball[i].second.second;
		ans[idx] = s - col[c] - wei[w];
		s += w;
		col[c] += w;
		wei[w] += w;
		if (i > 0 && c == ball[i - 1].second.first && w == ball[i - 1].second.second)
			ans[idx] = ans[ball[i - 1].first];
	}

	for (int i = 0; i < n; i++) cout << ans[i] << "\n";
}
