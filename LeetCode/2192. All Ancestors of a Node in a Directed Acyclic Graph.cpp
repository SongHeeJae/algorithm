/*
각 노드 x의 모든 자식 노드를 방문하면, x에는 방문하는 모든 자식 노드의 조상이 됩니다.
0번 노드부터 순회해주면, 각 노드의 조상은 오름차순으로 정렬됩니다.
*/

class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<int>> res;

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        res.resize(n);

        for(auto& e : edges) {
            graph[e[0]].push_back(e[1]);
        }

        for(int i=0; i<n; i++) {
            dfs(i, i);
        }

        return res;
    }

    void dfs(int cur, int node) {
        for(int nxt : graph[node]) {
            if(!res[nxt].empty() && res[nxt].back() == cur) {
                continue;
            }
            res[nxt].push_back(cur);
            dfs(cur, nxt);
        }
    }
};
