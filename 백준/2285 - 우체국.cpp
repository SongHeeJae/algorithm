#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> xa;
int n, x, a;
long long ls[100000], rs[100000], diff = 1e10;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &a);
		xa.push_back({ x, a });
	}
	sort(xa.begin(), xa.end());
	ls[0] = xa[0].second;
	rs[n - 1] = xa[n - 1].second;
	for (int i = 1; i < n; i++) {
		ls[i] = xa[i].second + ls[i - 1];
		rs[n - 1 - i] = xa[n - 1 - i].second + rs[n - i];
	}
	int idx = -1;
	for (int i = 0; i < n; i++) {
		long long d = abs(rs[i] - ls[i]);
		if (diff > d) {
			idx = i;
			diff = d;
		}
	}
	printf("%d", xa[idx].first);
}

/*
거리의 합이 최소가 되려면, 우체국은 어느 한 마을 위치에 지어져도 무방합니다.
우체국을 세울 위치를 구하려면, 우체국이 있는 지점에서 왼쪽과 오른쪽에 있는 사람의 수는 같거나 그 차이가 최소가 되어야합니다.
이를 구하기 위해 각 마을의 위치 오름차순으로 정렬한 뒤, 각 마을 별로 사람 수의 누적 합을 좌우 각각 구해주었습니다.
그 누적 합의 차가 최소인 지점이 사람의 수가 최소가 되는 지점이므로, 우체국이 세워질 위치입니다.
*/