#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, a, b;
vector<int> graph[32001];
int cnt[32001] = { 0 };
priority_queue<int> pq;

int main() {
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		cnt[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (cnt[i] == 0) pq.push(-i);
	while (!pq.empty()) {
		int val = -pq.top();
		pq.pop();
		printf("%d ", val);
		for (int i = 0; i < graph[val].size(); i++) {
			if (--cnt[graph[val][i]] == 0)
				pq.push(-graph[val][i]);
		}
	}
}

/*
위상정렬을 이용하여 해결하였습니다.
풀이는 아래 링크와 동일합니다.
https://blog.naver.com/gmlwo308/222301915946
*/