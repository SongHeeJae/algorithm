#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct hardComp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first) return a.second < b.second;
		else return a.first < b.first;
	}
};

struct easyComp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first) return a.second > b.second;
		else return a.first > b.first;
	}
};


// { 난이도, 문제 번호}
priority_queue<pair<int, int>, vector<pair<int, int>>, hardComp> hard;
priority_queue<pair<int, int>, vector<pair<int, int>>, easyComp> easy;
int level[100001] = { 0 };
int n, m, p, l, x;
string op;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> l;
		hard.push({ l, p });
		easy.push({ l, p });
		level[p] = l;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> op;
		if (op[0] == 'a') {
			cin >> p >> l;
			hard.push({ l, p });
			easy.push({ l, p });
			level[p] = l;
		}
		else if (op[0] == 'r') {
			cin >> x;
			if (x == 1) {
				while (level[hard.top().second] != hard.top().first) hard.pop();
				cout << hard.top().second << "\n";
			}
			else {
				while (level[easy.top().second] != easy.top().first) easy.pop();
				cout << easy.top().second << "\n";
			}
		}
		else {
			cin >> p;
			level[p] = 0;
		}
	}
}

/*
가장 어려운 문제와 쉬운 문제를 관리하는 우선순위 큐 두개를 관리하였습니다.
문제를 제거하게 되면 별도의 배열을 이용하여 기록해주었는데, 이전에 추천 문제 리스트에 있던 문제 번호가 다시 들어올 수 있었습니다.
그렇기 때문에 단순히 true false로만 기록한다면, 이미 제거되었던 문제가 pq에 아직 남아있는 상태에서 다시 들어온다면, 제거했는데도 제거된 지 모르게 되는 문제가 있었습니다.
하지만 동일한 문제는 다른 난이도로 다시 들어오기 때문에 문제의 난이도를 기억하여 이미 제거된 문제를 확인할 수 있었습니다.
*/