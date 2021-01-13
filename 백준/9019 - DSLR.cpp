#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int t, a, b;
bool visit[10000];

int D(int val) {
	return val * 2 % 10000;
}

int S(int val) {
	return (val + 9999) % 10000;
}

int LR(int val, int op) {
	int v[4];
	for (int i = 0; i<4; val /= 10, i++) v[i] = val % 10;
	for (int i = 0, j = op ? 2 : 0; i < 4; j = (j + 3) % 4, i++)
		val = val * 10 + v[j];
	return val;
}

string bfs() {
	queue<pair<int, string>> q;
	q.push({ a, "" });
	visit[a] = true;
	while (!q.empty()) {
		int val = q.front().first;
		string op = q.front().second;
		if (val == b) return op;
		q.pop();
		int d = D(val), s = S(val), l = LR(val, 1), r = LR(val, 0);
		if (!visit[d]) visit[d] = true, q.push({ d, op + "D" });
		if (!visit[s]) visit[s] = true, q.push({ s, op + "S" });
		if (!visit[l]) visit[l] = true, q.push({ l, op + "L" });
		if (!visit[r]) visit[r] = true, q.push({ r, op + "R" });
	}
	return "";
}

int main() {
	cin >> t;
	while (t--) {
		memset(visit, false, sizeof(visit));
		cin >> a >> b;
		cout << bfs() << "\n";
	}
}

/*

실행 시간이 너무 길어서 아래 코드로 수정하였습니다. 지나온 경로를 기억하여 바로 출력해줬습니다.

#include <iostream>
#include <queue>
#include <cstring>
int t, a, b, p[10000][2], d, s, l, r, c;
bool visit[10000];
char res[10000];
void bfs() {
	memset(visit, false, sizeof(visit));
	std::queue<int> q;
	q.push(a);
	visit[a] = true;
	while (!q.empty()) {
		int v = q.front();
		if (v == b) {
			c = 9999;
			for (int i = v; i != a; i = p[i][0]) res[c--] = p[i][1];
			printf("%s\n", res + c + 1);
			break;
		}
		q.pop();
		d = v * 2 % 10000, s = (v + 9999) % 10000;
		l = v / 1000 + (v % 10) * 10 + (v / 10 % 10) * 100 + (v / 100 % 10) * 1000;
		r = (v % 10) * 1000 + (v / 10 % 10) + (v / 100 % 10) * 10 + v / 1000 * 100;
		if (!visit[d]) visit[d] = true, q.push(d), p[d][0] = v, p[d][1] = 'D';
		if (!visit[s]) visit[s] = true, q.push(s), p[s][0] = v, p[s][1] = 'S';
		if (!visit[l]) visit[l] = true, q.push(l), p[l][0] = v, p[l][1] = 'L';
		if (!visit[r]) visit[r] = true, q.push(r), p[r][0] = v, p[r][1] = 'R';
	}
}
int main() {
	scanf("%d", &t); res[9999] = '\0';
	while (t-- && scanf("%d %d", &a, &b)) bfs();
}

*/

/*
아래와 같이 queue를 직접 구현하고, 모듈러 연산 실행 횟수를 줄였습니다.

#include <cstdio>
#include <cstring>
int t, a, b, p[10000][2], d, s, l, r, c, v, q[10000], f, g;
bool visit[10000];
char res[5000];
void bfs() {
	memset(visit, false, sizeof(visit));
	f = g = 0;
	q[f++] = a;
	visit[a] = true;
	while (1) {
		v = q[g++];
		if (v == b) {
			c = 4998;
			for (int i = v; i != a; i = p[i][0]) res[c--] = p[i][1];
			printf("%s\n", res + c + 1);
			break;
		}
		d = v * 2 % 10000, s = v ? v - 1 : 9999;
		l = (v * 10 + v / 1000) % 10000, r = v / 10 + (v % 10) * 1000;
		if (!visit[d]) visit[d] = true, q[f++] = d, p[d][0] = v, p[d][1] = 'D';
		if (!visit[s]) visit[s] = true, q[f++] = s, p[s][0] = v, p[s][1] = 'S';
		if (!visit[l]) visit[l] = true, q[f++] = l, p[l][0] = v, p[l][1] = 'L';
		if (!visit[r]) visit[r] = true, q[f++] = r, p[r][0] = v, p[r][1] = 'R';
	}
}
int main() {
	scanf("%d", &t); res[4999] = '\0';
	while (t-- && scanf("%d %d", &a, &b)) bfs();
}
*/

/*
각 명령어에 맞게 숫자를 변환 시켜주고, 지나온 명령어들을 계속 기억해주면서 BFS를 돌렸습니다.

최단 경로만 찾으면 되기때문에, 이미 방문했던 숫자에 대해서는 다시 방문하지 않았습니다.  
*/