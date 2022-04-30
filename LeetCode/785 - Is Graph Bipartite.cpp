/*
이분 그래프 문제였습니다.
현재 노드와 인접한 노드를 다른 값으로 기억해줍니다.
현재 노드의 값과 이미 방문했던 인접한 노드의 값이 서로 동일하다면, false를 반환해주면 됩니다.
*/

class Solution {
public:
    int visit[100] = {0};
    
    bool isBipartite(vector<vector<int>>& graph) {
        for(int i=0; i<graph.size(); i++) 
            if(!visit[i] && !dfs(graph, i, 1)) return false;
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, int node, int v) {
        visit[node] = v;
        for(auto nxt : graph[node]) {
            if(visit[nxt] == v) return false;
            if(!visit[nxt] && !dfs(graph, nxt, -v)) return false;
        }
        return true;
    }
};