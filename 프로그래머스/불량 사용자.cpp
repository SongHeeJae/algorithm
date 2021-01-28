#include <string>
#include <vector>
#include <set>
using namespace std;

vector<vector<string>> result;
set<string> visit, choice, dup;
string temp;

class Trie {
private:
    Trie* val[36];
    bool finished = false;
public:
    ~Trie() {
        for(int i=0; i<26; i++)
            if(val[i] != NULL) delete val[i];
    }
    
    int getValIdx(char ch) {
        if('0' <= ch && ch <= '9') return ch - '0' + 26;
        else return ch - 'a';
    }
    
    char getAlpOrNum(int idx) {
        if(idx >=26) return idx - 26 + '0';
        else return idx + 'a';
    }
    
    void insert(string& str, int idx) {
        if(idx == str.size()) {
            finished = true;
            return;
        }
        int valIdx = getValIdx(str[idx]);
        if(val[valIdx] == NULL)
            val[valIdx] = new Trie();
        val[valIdx]->insert(str, idx + 1);
    }
    
    void findByPattern(string& str, int idx, vector<string>& res) {
        if(idx == str.size()) {
            if(finished) res.push_back(temp);
            return;
        }
        if(str[idx] == '*') {
            for(int i=0; i<36; i++) {
                if(val[i] != NULL) {
                    temp.push_back(getAlpOrNum(i));
                    val[i]->findByPattern(str, idx+1, res);
                    temp.pop_back();
                }
            }
        } else {
            int valIdx = getValIdx(str[idx]);
            if(val[valIdx] != NULL) {
                temp.push_back(getAlpOrNum(valIdx));
                val[valIdx]->findByPattern(str, idx + 1, res);               
                temp.pop_back();
            }
        }
    }
};

void dfs(int idx) {
    if(idx == result.size()) {
        string d = "";
        for(string c : choice) d += c;
        dup.insert(d);
        return;
    }
    for(string res : result[idx]) {
        if(visit.find(res) != visit.end()) continue;
        visit.insert(res);
        choice.insert(res);
        dfs(idx + 1);
        choice.erase(res);
        visit.erase(res);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    Trie* root = new Trie();
    for(string uid : user_id)
        root->insert(uid, 0);
    
    for(string bid : banned_id) {
        vector<string> res;
        root->findByPattern(bid, 0, res);
        result.push_back(res);
    }
    
    dfs(0);
    return dup.size();
}

/*
Trie에 모든 유저 아이디를 넣어주고, 밴된 아이디 패턴을 이용해서 이용 가능한 유저 목록을 구해줬습니다.
그 후, 이용 가능한 유저 목록의 집합을 구하면서 중복을 제거해줬습니다.
*/