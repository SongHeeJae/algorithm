#include <iostream>
#include <cstring>

int t, n;
char word[11];
bool flag;
class Trie {
private:
	Trie* next[10];
	bool finish;
public:
	Trie() : finish(false) {
		memset(next, NULL, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (next[i]) delete next[i];
		}
	}

	void insert(char* w) {
		if (*w == '\0') {
			finish = true;
			for (int i = 0; i < 10; i++) {
				if (next[i]) {
					flag = true;
					break;
				}
			}
			return;
		}
		else {
			if (finish) flag = true;
			int n = *w - '0';
			if (next[n] == NULL) next[n] = new Trie();
			next[n]->insert(w + 1);
		}
	}
};

int main() {
	scanf("%d", &t);
	while (t--) {
		Trie* root = new Trie();
		flag = false;
		scanf("%d", &n);
		while (n--) {
			scanf("%s", word, sizeof(word));
			root->insert(word);
		}
		printf("%s\n", flag ? "NO" : "YES");
		delete root;
	}
}
