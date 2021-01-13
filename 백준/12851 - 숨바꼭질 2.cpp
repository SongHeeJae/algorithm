#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;
int n, k, f = INF;
int visit[100001] = { 0 };
int main() {
	scanf("%d %d", &n, &k);
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	while (!q.empty()) {
		int x = q.front().first;
		int c = q.front().second;
		if (f == INF && x == k) f = c;
		if (c > f) break;
		visit[x]++;
		q.pop();
		if (x > 0 && !visit[x - 1]) q.push({ x - 1, c + 1 });
		if (x < 100000 && !visit[x + 1]) q.push({ x + 1, c + 1 });
		if (2 * x < 100001 && !visit[2 * x]) q.push({ 2 * x, c + 1 });
	}
	printf("%d\n%d", f, visit[k]);
}


/*
현재 위치에서 지나갈 수 있는 경로는 무조건 push 해준 다음에, pop할 때마다 지금 도착한 장소의 count 값을 1씩 증가시켜줬습니다.  k에 도착하는 지점이 모두 pop되면, break를 걸어주었습니다.
*/