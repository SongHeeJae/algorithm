#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
#define INF 1e9
using namespace std;

int n, m, a, b, c;
int d[MAX][MAX];
int p[MAX][MAX];
vector<int> route;

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) d[i][j] = INF;
		d[i][i] = 0;
	}
}

void floyd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (d[j][k] > d[j][i] + d[i][k]) {
					d[j][k] = d[j][i] + d[i][k];
					p[j][k] = i;
				}
			}
		}
	}
}

void printDist() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (d[i][j] != INF ? d[i][j] : 0) << " ";
		}
		cout << "\n";
	}
}

void findRoute(int s, int e) {
	if (p[s][e] == 0) return;
	findRoute(s, p[s][e]);
	route.push_back(p[s][e]);
	findRoute(p[s][e], e);
}

void printRoute(int s, int e) {
	route.clear();
	route.push_back(s);
	findRoute(s, e);
	route.push_back(e);
	cout << route.size() << " ";
	for (int r : route) cout << r << " ";
	cout << "\n";
}

bool isMovable(int s, int e) {
	return d[s][e] != 0 && d[s][e] != INF;
}

void printRoutes() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (isMovable(i, j)) printRoute(i, j);
			else cout << "0\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	init();

	while (m--) {
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}

	floyd();
	printDist();
	printRoutes();
}

/*
플로이드를 이용하여 풀이하였습니다.
A에서 B로 가는 최소 비용을 구해주고, 경로 추적을 위해 A와 B사이의 경유 도시를 기억해주었습니다.
*/