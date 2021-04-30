#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;

class Trie {
private:
	map<string, Trie*> m;
public:
	~Trie() {
		for (auto it = m.begin(); it != m.end(); it++) {
			delete it->second;
		}
	}

	void insert(vector<string>& foods, int idx) {
		if (foods.size() == idx) return;
		Trie* find;
		auto f = m.find(foods[idx]);
		if (f == m.end()) {
			find = new Trie();
			m.insert({ foods[idx], find});
		}
		else {
			find = f->second;
		}
		find->insert(foods, idx + 1);
	}

	void dfs(int depth) {
		vector<pair<string, Trie*>> temp;
		for (auto it = m.begin(); it != m.end(); it++) {
			temp.push_back({ it->first, it->second });
		}
		sort(temp.begin(), temp.end());
		for (int i = 0; i < temp.size(); i++) {
			for (int j = 0; j < depth; j++) {
				cout << "--";
			}
			cout << temp[i].first << "\n";
			temp[i].second->dfs(depth + 1);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Trie* root = new Trie();

	cin >> n;

	vector<string> temp;
	string str;
	while (n--) {
		temp.clear();
		cin >> k;
		while (k--) {
			cin >> str;
			temp.push_back(str);
		}
		root->insert(temp, 0);
	}
	root->dfs(0);

	delete root;
}

/*
트라이를 이용하여 풀었습니다.
로봇 개미가 얻어온 정보들을 트라이에 삽입해준 뒤,
저장된 모든 먹이 정보들을 오름차순 정렬하여 탐방하며 출력해주었습니다.
*/