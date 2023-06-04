/*
DFS를 이용하여 연결된 그룹의 수를 찾아주었습니다.
*/

class Solution {
public:
    bool visit[200] = {false};

    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        for(int i=0; i<isConnected.size(); i++) {
            if(visit[i]) continue;
            dfs(i, isConnected);
            res++;
        }
        return res;
    }

    void dfs(int city, vector<vector<int>>& isConnected) {
        if(visit[city]) return;
        visit[city] = true;
        for(int i=0; i<isConnected[city].size(); i++) {
            if(isConnected[city][i]) dfs(i, isConnected);
        }
    }
};
