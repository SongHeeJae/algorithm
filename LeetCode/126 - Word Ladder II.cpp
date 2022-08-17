/*
BFS와 DFS + DP를 이용하여 풀 수 있었습니다.

가장 짧은 경로의 길이를 구해준 뒤, DFS를 수행하면서 모든 경로를 찾아줍니다.

이 때, 각 단어와 depth를 이용하여 도달하지 못하는 경로는 제거해주었습니다.
*/

class Solution {
public:
    bool v[500] = {false};
    
    vector<vector<string>> result;
    vector<string> temp;
    map<string, int> dp; // {word, depth} - word가 depth 이하일 때는 어차피 도달 불가능 (DFS)
    int shortestCount; // 가장 짧은 경로 길이
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        shortestCount = findShortestCount(beginWord, endWord, wordList);
        
        memset(v, false, sizeof(v));
        temp.push_back(beginWord);
        
        dfs(beginWord, endWord, wordList, 0);
        
        return result;
    }
    
private:
    int findShortestCount(string& beginWord, string& endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 0});

        while(!q.empty()) {
            string word = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if(word == endWord) return cnt;
            
            for(int i=0; i<wordList.size(); i++) {
                if(v[i] || !isMovable(word, wordList[i])) continue;
                v[i] = true;
                q.push({wordList[i], cnt + 1});
            }
        }
        return 0;
    }
    
    bool dfs(string& curWord, string& endWord, vector<string>& wordList, int depth) {
        if(depth == shortestCount) {
            if(curWord != endWord) return false;
            result.push_back(temp);
            return true;
        }
        
        if(dp.find(curWord) != dp.end() && dp[curWord] <= depth)
            return false;
        
        bool movable = false;
        
        for(int i=0; i<wordList.size(); i++) {
            if(v[i] || !isMovable(curWord, wordList[i])) continue;
               
            v[i] = true;
            temp.push_back(wordList[i]);
            movable = movable | dfs(wordList[i], endWord, wordList, depth + 1);
            temp.pop_back();
            v[i] = false;
        }
        
        if(!movable) dp[curWord] = depth;
        
        return movable;
    }
    
    bool isMovable(string& cur, string& next) {
        int diff = 0;
        for(int i=0; i<cur.size(); i++) {
            diff += cur[i] != next[i];
            if(diff > 1) return false;
        }
        return true;
    }
};
