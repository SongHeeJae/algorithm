#include <iostream>
#include <map>
using namespace std;

int u, v;
map<int, int> indegree;

void initIndegree(int node) {
	if (indegree.find(node) == indegree.end()) {
		indegree.insert({ node, 0 });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int k = 1; ; k++) {
		indegree.clear();

		while (1) {
			cin >> u >> v;
			if (u <= 0 && v <= 0) break;
			initIndegree(u);
			initIndegree(v);
			indegree[v]++;
		}

		if (u < 0 && v < 0) break;

		int nodeCnt = indegree.size();
		int rootCnt = 0, leafCnt = 0;
		for (auto& elem : indegree) {
			if (elem.second == 0) rootCnt++;
			else if (elem.second == 1) leafCnt++;
		}

		if (rootCnt == 1 && leafCnt == nodeCnt - 1 || indegree.size() == 0)
			cout << "Case " << k << " is a tree.\n";
		else
			cout << "Case " << k << " is not a tree.\n";
	}
}

/*
트리인지 판별하기 위해 각 노드들의 진입 차수를 이용하였습니다.
트리라면,
진입 차수가 없는 루트 노드 1개와 진입 차수가 하나씩 있는 나머지 리프 노드들로 구성되어 있습니다.
*/