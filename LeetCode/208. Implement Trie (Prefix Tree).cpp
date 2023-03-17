/*
트라이 구현 문제였습니다.
*/

class Trie {
public:
    Trie() {
        for(int i=0;i<26; i++) nextTrie[i] = NULL;
    }
    
    void insert(string word) {
        insertInternal(word, 0);
    }
    
    bool search(string word) {
        return searchInternal(word, 0);
    }
    
    bool startsWith(string prefix) {
        return startsWithInternal(prefix, 0);
    }
    
private:
    bool flag = false;
    Trie* nextTrie[26];

    void insertInternal(string& word, int wordIdx) {
        if(isLast(word, wordIdx)) {
            flag = true;
            return;
        }
        int nxtIdx = word[wordIdx] - 'a';
        if(nextTrie[nxtIdx] == NULL) nextTrie[nxtIdx] = new Trie();
        nextTrie[nxtIdx]->insertInternal(word, wordIdx + 1);
    }

    bool searchInternal(string& word, int wordIdx) {
        if(isLast(word, wordIdx)) return flag;
        int nxtIdx = word[wordIdx] - 'a';
        if(nextTrie[nxtIdx] == NULL) return false;
        return nextTrie[nxtIdx]->searchInternal(word, wordIdx+1);
    }

    bool startsWithInternal(string& word, int wordIdx) {
        if(isLast(word, wordIdx)) return true;
        int nxtIdx = word[wordIdx] - 'a';
        if(nextTrie[nxtIdx] == NULL) return false;
        return nextTrie[nxtIdx]->startsWithInternal(word, wordIdx + 1);
    }

    bool isLast(string& word, int wordIdx) {
        return word.size() == wordIdx;
    }
};
