#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;

int n, p[MAX], s = 0;
pair<int, int> arr[MAX];

int find(int x) {
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].second >> arr[i].first;
		p[i] = i;
	}

	sort(arr + 1, arr + n + 1);

	for (int i = n; i > 0; i--) {
		int nxt = find(arr[i].second);
		if (nxt != 0) {
			s += arr[i].first;
			p[nxt] = nxt - 1;
		}
	}
	cout << s;
}

/*
먼저, 컵라면 수로 내림차순 정렬해줍니다.
데드라인이 x라면, 해당 문제는 미룰 수 있는 만큼 최대한 미뤄줍니다.

예를 들어,
(데드라인, 컵라면 수) = [(5, 40), (5, 30), (5, 20)] 처럼 정렬되었을 때,
1번 문제는 5시간 내에 풀면 됩니다. 5시간이 지났을 때 풀어줍시다.
2번 문제는 5시간 내에 풀면 됩니다. 5시간이 지났을 때는 이미 1번 문제를 풀기로 했으므로, 4시간이 지났을 때 풀어줍시다.
3번 문제는 5시간 내에 풀면 됩니다. 5시간이 지났을 때는 이미 1번 문제를 풀기로 했고, 4시간이 지났을 때는 이미 2번 문제를 풀기로 했으므로, 3시간이 지났을 때 풀어줍시다.

즉, 컵라면 수 내림차순으로 정렬된 문제를 순차적으로 탐색하면서,
x시간 내에 아직 문제가 정해지지 않은 시간 대에 풀어주면 되는 것입니다.

물론, 아직 문제가 정해지지 않은 시간 대를 순차적으로 찾아내려면 시간 초과를 받게 됩니다.
이를 해결하기 위해 유니온 파인드를 이용하였습니다.
*/