#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, c, m, s, e, v, ans = 0;
int cap[10000] = { 0 };
vector<vector<int>> box;

bool comp(vector<int>& a, vector<int>& b) {
	if (a[1] == b[1]) {
		return a[0] < b[0];
	}
	else {
		return a[1] < b[1];
	}
}

int main() {
	scanf("%d %d %d", &n, &c, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &s, &e, &v);
		box.push_back({ s, e, v });
	}
	sort(box.begin(), box.end(), comp);
	for (int i = 0; i < m; i++) {
		int m = 0;
		for (int j = box[i][0]; j < box[i][1]; j++)
			m = max(m, cap[j]);
		int val = min(box[i][2], c - m);
		for (int j = box[i][0]; j < box[i][1]; j++)
			cap[j] += val;
		ans += val;
	}
	printf("%d", ans);
}

/*
도착지, 출발지 순으로 오름차순 정렬해줍니다.

각 지점마다 처리한 박스의 개수를 저장해줄 것입니다.

이전에 방문했던 지점은 돌아갈 수 없습니다.

각 박스의 시작점부터 도착점 사이에 박스를 넣을 수 있는 갯수를 구해줍니다.

그 갯수만큼 박스를 처리해줍니다.
*/