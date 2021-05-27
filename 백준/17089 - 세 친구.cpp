#include<bits/stdc++.h>
#define INF 12000
using namespace std;
int n, m, a, b, ans = INF, c[4000] = { 0 };
vector<int> g[4000];
int main() {
	scanf("%d %d", &n, &m);
	while (m-- && scanf("%d %d", &a, &b)) {
		c[--a]++, c[--b]++;
		if (b < a) swap(a, b);
		g[a].push_back(b);
	}
	for (int i = 0; i < n; i++) for (int j : g[i]) for (int k : g[j])
		if (find(g[i].begin(), g[i].end(), k) != g[i].end()) ans = min(ans, c[i] + c[j] + c[k]);
	printf("%d", ans != INF ? ans - 6 : -1);
}

/*
예제 입력 1을 그래프로 나타내면 다음과 같습니다.
1ㅡ2
|/ | 
3ㅡ4ㅡ5
세 노드가 사이클을 이룰 때, 세 명이 서로 친구입니다.
번호가 더 작은 친구에서 번호가 더 큰 친구로 가는 방향 그래프로 가정 하겠습니다. (위 그림은 방향 생략)
1에서 2가 친구라면, 2와 친구인 사람들이 1이랑도 친구인지 판별해주면 됩니다.
세 친구 관계에서 서로의 수는 제외시켜야하므로 -6을 해줍니다.
*/