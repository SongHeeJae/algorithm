#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int t, v, e, a, b, f, color[20001]; // 위 설명에서 말한 -1과 1을 color로 표현.
vector<vector<int>> graph;
bool visit[20001];
void dfs(int node, int c) {
	visit[node] = true;
	color[node] = c;
	for (int i = 0; i < graph[node].size(); i++) {
		int nextNode = graph[node][i];
		if (visit[nextNode]) {
            // 현재 정점과 이미 방문했던(중복으로 연결된) 정점의 값이 다르다면, 이분 그래프 X 
			if (color[nextNode] == c) f = 0;
			continue;
		}
		dfs(nextNode, -1 * c);
	}
}
int main() {
	scanf_s("%d", &t);
	while (t-- && scanf("%d %d", &v, &e)) {
		memset(visit, false, sizeof(visit));
		graph.clear();
		graph.resize(v + 1);
		f = 1;
		while (e-- && scanf("%d %d", &a, &b)) {
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for (int i = 1; i <= v; i++) { // 연결되지 않은 모든 그래프에 대하여 방문하기 위함
			if (!visit[i]) dfs(i, -1);
			if (!f) break; // 이미 이분 그래프가 아니라면 break;
		}
		if (f) printf("YES\n");
		else printf("NO\n");
	}
}

/*
먼저, 이분 그래프에 정의에 대해 이해한 뒤에 문제를 풀 수 있었습니다.
예를 들어, 현재 정점이 -1의 값을 가진다면, 인접한 정점은 1의 값을 가져야합니다.
즉, 각 정점은 -1 또는 1의 값 중 하나만 가질 수 있습니다.
예를 들어, 정점이 5개인 아래와 같은 형태의 그래프인 경우를 보겠습니다.

1---2
  / |
4---3    5

1번 정점이 -1의 값을 가진 채, 이곳에서부터 DFS로 차례로 방문한다생각하면, 
2번 정점은 1의 값을 가져야하므로, 3번과 4번 정점은 -1의 값을 가져야합니다.
하지만 3번 정점이 -1의 값을 가지는 순간, 4번 정점은 1의 값을 가져야하기도 합니다.
따라서 위 그래프는 이분 그래프가 아닙니다.

위에서 말한 조건이 모든 정점에서 성립하면, 이분 그래프라고 볼 수 있었습니다.
그리고 위에서 예시로 보여준 그래프처럼, 케이스로 나오는 그래프는 꼭 연결 그래프가 아닐 수도 있습니다.
연결되지 않은 여러 개의 그래프가 모두 이분 그래프라면, 이분 그래프가 될 수 있습니다.

하지만 연결되지 않은 여러 개의 그래프 중 하나라도 이분 그래프를 만족하지 않는다면, 이분 그래프가 될 수 없습니다. 이를 판별하기 위해 모든 정점에 대하여 이분 그래프인지 판별을 수행해줬습니다.
*/