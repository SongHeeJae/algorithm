#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
#define INF 2147483647

int n;
int dist[MAX - 1];
int price[MAX];
int mn = INF;
long long ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> dist[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}

	for (int i = 0; i < n - 1; i++) {
		mn = min(mn, price[i]);
		ans += (long long)mn * dist[i];
	}
	cout << ans;
}

/*
주유소를 방문할 때마다 최소 가격을 업데이트해주고, 
그 가격으로 다음 주유소로 이동할 수 있는 만큼 기름을 넣어주었습니다.
*/