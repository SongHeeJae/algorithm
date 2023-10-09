/*
trie 구조를 이용하여 풀 수 있었습니다.
모든 단어를 trie에 삽입해주고, 이전 알파벳이 있는 단어에 한해 모든 단어를 검사하며 longest word를 찾아줍니다.
longest word를 찾을 때에는 알파벳 작은 순으로 검사해주면, 사전 작은순으로 찾을 수 있게 됩니다.
*/

class Trie {
    Trie* children[26];
    bool finished = false;

public:
    Trie(bool finished) {
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
        this->finished = finished;
    }

    void insert(string& word) {
        insert(word, 0);
    }

    string findLongestWord() {
        string res = "", temp = "";
        findLongestWordInternal(temp, res);
        return res;
    }

private:
    void insert(string& word, int idx) {
        if(word.size() == idx) {
            finished = true;        
            return;
        }

        int cIdx = word[idx] - 'a';
        if(!children[cIdx]) {
            children[cIdx] = new Trie(false);
        }

        children[cIdx]->insert(word, idx + 1);
    }

    void findLongestWordInternal(string& temp, string& res) {
        if(!finished) return;

        if(temp.size() > res.size()) {
            res = temp;
        }
        
        for(int i=0; i<26; i++) {
            if(children[i]) {
                temp.push_back(i + 'a');
                children[i]->findLongestWordInternal(temp, res);
                temp.pop_back();
            }
        }
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* root = new Trie(true);
        for(string& word : words) {
            root->insert(word);
        }
        return root->findLongestWord();
    }
};
