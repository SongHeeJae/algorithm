/*
Trie 문제였습니다. search를 수행하다가 dot을 만난다면, 모든 알파벳 노드를 검사해주면 됩니다.
*/

class WordDictionary {
public:
    WordDictionary() {
        for(int i=0; i<26; i++) {
            dict[i] = NULL;
        }
    }
    
    void addWord(string word) {
        return addWordInternal(word, 0);
    }
    
    bool search(string word) {
        return searchInternal(word, 0);
    }
private:
    WordDictionary* dict[26];
    bool flag = false;

    void addWordInternal(string& word, int idx) {
        if(idx == word.size()) {
            flag = true;
            return;
        }

        int dictIdx = word[idx] - 'a';
        if(dict[dictIdx] == NULL) {
            dict[dictIdx] = new WordDictionary();
        }

        dict[dictIdx]->addWordInternal(word, idx + 1);
    }

    bool searchInternal(string& word, int idx) {
        if(idx == word.size()) {
            return flag;
        }

        if(word[idx] == '.') {
            return searchInternalWhenCharIsDot(word, idx);
        } 
        return searchInternalWhenCharIsLetter(word, idx);
    }

    bool searchInternalWhenCharIsDot(string& word, int idx) {
        for(int i=0; i<26; i++) {
            if(dict[i] == NULL) {
                continue;
            }

            bool res = dict[i]->searchInternal(word, idx + 1);
            if(res) {
                return true;
            }
        }
        return false;
    }

    bool searchInternalWhenCharIsLetter(string& word, int idx) {
        int dictIdx = word[idx] - 'a';
        if(dict[dictIdx] == NULL) {
            return false;
        }
        return dict[dictIdx]->searchInternal(word, idx + 1);
    }
};
