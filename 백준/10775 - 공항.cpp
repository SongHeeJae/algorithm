#include <iostream>
#define MAX 100001
using namespace std;

int g, p, d[MAX]; 

int findParent(int x) {
	if (d[x] == x) return x;
	else return d[x] = findParent(d[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> g >> p;
	for (int i = 1; i <= g; i++) d[i] = i;
	
	int cnt = 0;
	for (; cnt < p; cnt++) {
		cin >> g;
		int nxt = findParent(g);
		if (!nxt) break;
		d[nxt] = nxt - 1;
	}
	cout << cnt;
}

/*
각 비행기는 도킹할 수 있는 가장 높은 번호의 게이트에 도킹시켜주었습니다.
유니온 파인드 알고리즘을 이용해서 도킹할 수 있는 게이트를 빠르게 찾아주었습니다.
*/