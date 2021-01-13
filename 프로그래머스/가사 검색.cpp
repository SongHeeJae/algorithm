#include <string>
#include <vector>
using namespace std;

class Trie {
private:
    int cnt = 0;
    Trie *alp[26];
public:
    ~Trie() {
        for(int i=0; i<26; i++) {
            if(alp[i] != NULL) delete alp[i];
        }
    }
    void insert(string& word, int idx, bool reverse) {
        cnt++; // 지나간 경로 ++; 루트의 cnt에는 모든 단어의 개수가 들어감
        if(idx == (reverse ? -1 : word.size())) return;
        int alp_idx = word[idx] - 'a';
        if(alp[alp_idx] == NULL) alp[alp_idx] = new Trie();
        alp[alp_idx]->insert(word, reverse ? idx - 1 : idx + 1, reverse);
    }
    
    int count(string& query, int idx, bool reverse) {
        if(query[idx] == '?') return cnt; // '?'를 만났다면 현재지점의 cnt 반환
        else if(alp[query[idx]-'a'] != NULL)
            return alp[query[idx]-'a']->count(query, reverse ? idx - 1 : idx + 1, reverse);
        else return 0;
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    Trie* trie[10000]; // 각 단어의 길이만큼 생성
    Trie* rtrie[10000];
    for(int i=0; i<words.size(); i++) {
        int idx = words[i].size()-1;
        if(trie[idx] == NULL) {
            trie[idx] = new Trie();
            rtrie[idx] = new Trie();
        }
        trie[idx]->insert(words[i], 0, false);
        rtrie[idx]->insert(words[i], words[i].size()-1, true);
    }
    for(int i=0; i<queries.size(); i++) {
        int idx = queries[i].size()-1;
        int ret = 0;
        if(queries[i][0] == '?' && queries[i][idx] == '?') { // '?'로만 이루어진 문자열
            if(trie[idx] != NULL)
                ret = trie[idx]->count(queries[i], 0, false);
        } else {
           if(trie[idx] != NULL)
                ret = queries[i][0] == '?' ? rtrie[idx]->count(queries[i], idx, true) : trie[idx]->count(queries[i], 0, false);
        }
        answer.push_back(ret);
    }
    return answer;
}
[출처] 프로그래머스 : 가사 검색|작성자 쿠케캬캬