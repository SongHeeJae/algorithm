#include <string>
#include <vector>
#include <queue>
using namespace std;

bool isMovable(string& cur, string& next) {
    int cnt = 0;
    for(int i=0; i<cur.size(); i++) {
        if(cur[i] != next[i]) cnt++;
    }
    return cnt == 1;
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    vector<vector<int>> graph(words.size());
    vector<bool> visit(words.size(), false);
    queue<pair<int, int>> q;
    q.push({words.size()-1, 0});
    visit[words.size()-1] = true;
    while(!q.empty()) {
        int idx = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(words[idx] == target) {
            return depth;
        }
        for(int i=0; i<words.size(); i++) {
            if(!visit[i] && isMovable(words[idx], words[i])) {
                q.push({i, depth + 1});
                visit[i] = true;
            }
        }
    }
    
    return 0;
}