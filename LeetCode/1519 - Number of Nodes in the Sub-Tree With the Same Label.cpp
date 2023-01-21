/*
dfs를 수행하며 각 노드에서 모든 하위 노드의 label 개수를 구해주면 됩니다.
모든 하위 노드를 우선 방문하고, 현재 노드 label 개수를 확인합니다.
*/

class Solution {
public:
    vector<vector<int>> graph;
    vector<int> result;

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        graph.resize(n);
        result.resize(n);
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1, labels);
        return result;
    }

    int* dfs(int node, int prv, string& labels) {
        int cnt[26] = { 0 };
        for(int nxt : graph[node]) {
            if(prv == nxt) continue;
            int* res = dfs(nxt, node, labels);
            for(int i=0;i<26;i++) cnt[i] += res[i];
        }
        cnt[labels[node] - 'a']++;
        result[node] = cnt[labels[node] - 'a'];
        return cnt;
    }
};

