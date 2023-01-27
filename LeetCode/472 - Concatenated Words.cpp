/*
DFS를 이용하여 풀 수 있었습니다.
모든 단어를 set에 초기화해준 뒤, 각 단어가 2개 이상의 단어 조합으로 만들어질 수 있는지 탐색해줍니다.
임시 문자열에 각 단어의 알파벳을 순차적으로 추가하며, set에 들어있는지 확인합니다.
set에 들어있다면, 해당 위치까지 단어를 슬라이싱하고, 다음 위치부터 다시 탐색해줍니다.
단어가 빈 문자열까지 슬라이싱 되었을 때 2개 이상의 단어가 사용되었는지 검사해줍니다.
*/

class Solution {
public:
    set<string> wordSet;
    vector<string> result;

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(string& word : words) wordSet.insert(word);    
        
        for(string& word : words)
            if(dfs(word, 0)) result.push_back(word);

        return result;
    }

    bool dfs(string& word, int depth) {
        if(word.length() == 0) {
            if(depth >= 2) return true;
            return false;
        }

        string temp = "";
        for(int i=0; i<word.size(); i++) {
            temp.push_back(word[i]);
            if(wordSet.find(temp) == wordSet.end()) continue;
            string nxt = word.substr(i + 1);
            if(dfs(nxt, depth + 1)) return true;
        }

        return false;
    }
};
