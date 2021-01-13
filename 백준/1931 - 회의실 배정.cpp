#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b) {
	return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main() {
	int n, s, e, c = 1, j = 0;
	scanf("%d", &n);
	vector<pair<int, int>> time(n);
	for (int i = 0; i < n && scanf("%d %d", &s, &e); i++) time[i] = make_pair(s, e);
	sort(time.begin(), time.end(), comp);
	for (int i = 1; i < n; i++)
		if (time[i].first >= time[j].second) {
			c++;
			j = i;
		}
	printf("%d\n", c);
}