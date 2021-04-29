#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k, a, b;
int cnt[100001] = { 0 };
int build[100001] = { 0 };
vector<int> graph[100001];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	while (m-- && scanf("%d %d", &a, &b)) {
		graph[a].push_back(b);
		cnt[b]++;
	}
	while (k-- && scanf("%d %d", &a, &b)) {
		if (a == 1) {
			if (cnt[b] > 0) break;
			for (int i = 0; i < graph[b].size(); i++)
				cnt[graph[b][i]]--;
			build[b]++;
		}
		else {
			if (build[b] <= 0) break;
			if (--build[b] == 0) {
				for (int i = 0; i < graph[b].size(); i++)
					cnt[graph[b][i]]++;
			}
		}
	}
	printf("%s", k == -1 ? "King-God-Emperor" : "Lier!");
}

/*
각 건물을 건설하기 위해 필요한 건물의 개수를 기억해줍니다.
건물을 건설할 때는, 현재 건물을 건설하기 위해 필요한 건물의 개수가 0개라면 건설할 수 있습니다.
건물을 건설한 뒤, 현재 건물을 선행 건물로 가지는 건물들의 필요한 건물의 개수를 하나 차감시켜줍니다.
건설된 건물의 개수를 기억해줍니다.
건물을 파괴할 때는,  현재 건물이 건설된 적이 있는지 확인해줍니다.
지어져있던 건물이 다 파괴되었으면, 해당 건물을 선행 건물로 가지는 건물들의 필요한 선행 건물 개수를 하나씩 다시 증가시켜줍니다. 
*/