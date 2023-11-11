/*
dfs를 이용하여 풀 수 있었습니다. 1번 노드부터 시작해서, 0~9번 노드를 순차적으로 방문하면서 덧붙여준다고 보면 됩니다. 
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1; i<10; i++) dfs(res, i, n);
        return res;
    }

    void dfs(vector<int>& res, int val, int n) {
        if(val > n) return;
        res.push_back(val);
        for(int i=0; i<10; i++) dfs(res, val * 10 + i, n);
    }
};
