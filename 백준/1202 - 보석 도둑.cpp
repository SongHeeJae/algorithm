#include <iostream>
#include <algorithm>
#include <set>
#define MAX 300000
using namespace std;

int n, k, b;
long long ans = 0;
multiset<int> c;
pair<int, int> mv[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> mv[i].second >> mv[i].first;
	}
	for (int i = 0; i < k; i++) {
		cin >> b;
		c.insert(b);
	}

	sort(mv, mv + n);
	
	for (int i = n - 1; i >= 0 && !c.empty(); i--) {
		int vv = mv[i].first;
		int mm = mv[i].second;
		auto it = c.lower_bound(mm);
		if (it == c.end()) continue;
		c.erase(it);
		ans += vv;
	}
	cout << ans;
}

/*
가격 순으로 보석을 내림차순 정렬하고, 
가격이 높은 순으로 가방에 담되, 그 보석을 담을 수 있는 가장 낮은 무게 제한의 가방에 담아주었습니다.
예를 들어, 보석의 가격과 무게가 [{99, 2}, {65, 1}, {23, 5}] 일 때,
99의 보석을 담기 위해 무게가 2 이상인 가장 작은 가방을 찾아주고,
65의 보석을 담기 위해 무게가 1 이상인 가장 작은 가방을 찾아주었습니다.
이를 빠르게 찾기 위해 lower bound 알고리즘을 이용하였습니다.
*/