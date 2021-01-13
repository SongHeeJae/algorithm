#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sc[] = { 0,0,1,1,2,3,5,11 };
int dx[] = { -1,1,0,0,1,1,-1,-1 };
int dy[] = { 0,0,-1,1,-1,1,-1,1 };
int w, b;
bool v[4][4];
string Boggle[4];
vector<string> str;

class Trie {
public :
	Trie* alp[26];
	bool finished;
	bool visit[30]; // 각 b 단계에서 방문 여부
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (alp[i]) delete alp[i];
	}
	void insert(string& s, int c) {
		if (c == s.length()) {
			finished = true;
			return;
		}
		int idx = s[c] - 'A';
		if (alp[idx] == NULL) alp[idx] = new Trie();
		alp[idx]->insert(s, c + 1);
	}

	void dfs(string &s, int x, int y, int t) {
		if (finished && !visit[t])
			visit[t] = true, str.push_back(s);
		if (v[x][y]) return;
		v[x][y] = true;
		int idx = Boggle[x][y] - 'A';
		if (alp[idx]) {
			s.push_back(Boggle[x][y]);
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
				alp[idx]->dfs(s, nx, ny, t);
			}
			s.pop_back();
		}
		v[x][y] = false;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Trie* root = new Trie();
	cin >> w;;
	while (w--) {
		string s;
		cin >> s;
		root->insert(s, 0);
	}
	cin >> b;
	for (int i = 0; i < b; i++) {
		str.clear();
		int score = 0;
		string longestWord = "";
		for (int j = 0; j < 4; j++) cin >> Boggle[j];
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				string s;
				root->dfs(s, j, k, i);
			}
		}
		for (int i = 0; i < str.size(); i++) {
			score += sc[str[i].length() - 1];
			if (str[i].length() > longestWord.length() || str[i].length() == longestWord.length() && longestWord > str[i])
				longestWord = str[i];
		}
		cout << score << " " << longestWord << " " << str.size() << "\n";
	}
	delete root;
}

/*
트라이에 모든 단어를 입력해준 뒤에, Boggle의 모든 시작점을 기준으로 모두 DFS를 돌아줬습니다.
현재 검사하고 있는 Boggle 위치의 알파벳이 트라이에 저장되어있다면, 8방향으로 이동 후 계속 들어가면서 단어가 저장된 지점인 경우에(finished == true) 단어를 저장해주었습니다.
각 단어의 중복을 방지하기위해서 클래스 내에 단어의 방문 여부를 표시하였습니다.

문제 이해하는데에도 한참이 걸렸는데, 하나의 단어에 대해서는 같은 위치의 알파벳을 중복 접근할 수 없습니다.
다른 단어끼리는 알파벳을 중복 접근해도 됩니다.
*/