#include <iostream>
#include <queue>
#include <cstring>
bool visit[1000000];
int t, n, p[1000000] = { 0,-1 }, num[1000000] = { 0,1 };
void print(int val) {
	if (val == -1) return;
	print(p[val]);
	printf("%d", num[val]);
}
bool bfs() {
	if (n == 1) { p[0] = -1, num[0] = 1; return true; }
	memset(visit, false, sizeof(visit));
	visit[1] = true;
	std::queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (!x) return true;
		for (int i = 0; i < 2; i++) {
			int xx = (x * 10 + i) % n;
			if (visit[xx]) continue;
			visit[xx] = true;
			p[xx] = x;
			num[xx] = i;
			q.push(xx);
		}
	}
	return false;
}
int main() {
	scanf("%d", &t);
	while (t-- && scanf("%d", &n)) {
		if (bfs()) print(0);
		else printf("BRAK");
		printf("\n");
	}
}

/*
먼저 모듈러 연산에 대해서는 다음이 성립한다는 것을 알아둘 필요가 있었습니다.

﻿(A + B) % MOD = ( (A % MOD) + (B % MOD) ) % MOD
(A * B) % MOD = ( (A % MOD) * (B % MOD) ) % MOD
(A - B) % MOD = ( (A % MOD) - (B % MOD) ) % MOD
덧셈에 대해서 증명해보면, 

상수 C(C >= 0), 몫 Q, 나머지 R(0 <= R < C)에 대하여,
A = C * Q1 + R1
B = C * Q2 + R2 입니다.

따라서,
(A + B) % C
= ( (C * Q1 + R1) + (C * Q2 + R2) ) % C
= ( C * Q1 + R1 + C * Q2 + R2 ) % C
= ( C * (Q1 + Q2) + R1 + R2 ) % C // 모듈러 연산에 대해서는 나머지만 남게됩니다.
= (R1 + R2) % C // R1 = A % C, R2 = B % C
= ( (A % C) + (B % C) ) % C 
위와 같습니다.

​

먼저, 수는 0으로 시작하면 안되므로, A=1로 시작합니다.

0을 붙이려면 A*10,

1을 붙이려면 A*10 + 1을 해주면됩니다.

오버플로우가 나는 것을 방지하기 위해, 아래와 같이 모듈러 연산을 해줍니다.

(A * 10) % MOD

(A * 10 + 1) % MOD

각각의 연산에 어떠한 수를 붙인 것인지 기억해줍니다.

수의 최솟값을 찾아야하므로, 0을 붙이는 연산을 먼저 수행해주고,  방문했던 나머지 수에 대해서는 재방문하지 않습니다.

결국 방문했던 나머지 수가 0이라면, N의 배수인 수를 찾은 셈이므로, 수행했던 연산을 역추적하여 0 또는 1을 출력해줍니다.

방문했던 나머지 수가 0이었던 적이 없다면, 범위 내에 구사과가 좋아하는 수가 없으므로 "BRAK"을 출력해줍니다.

*/