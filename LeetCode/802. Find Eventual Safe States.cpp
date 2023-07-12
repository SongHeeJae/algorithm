/*
각 노드가 terminal node에 도달할 수 있는지 판별해줘야 합니다.
위상정렬을 이용하여 풀 수 있었습니다.
주어진 그래프를 이용하여, 각 노드로 들어오는 간선을 확인합니다.
terminal node에 도달할 수 있는지 판별하려면, terminal node에서부터 시작되는 역방향 간선을 이용하면 됩니다.
초기에 terminal node를 찾아주고, 역방향 연결된 노드들을 위상정렬을 통해 탐색해나가면 됩니다.
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> g(n);
        vector<int> ind(n, 0);
        queue<int> q;
        for(int i=0; i<graph.size(); i++) {
            vector<int>& edges = graph[i];
            for(int e : edges) {
                g[e].push_back(i);
                ind[i]++;
            }
            if(edges.size() == 0) q.push(i);
        }

        vector<int> res;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            res.push_back(node);
            for(int nxt : g[node])
                if(--ind[nxt] == 0) q.push(nxt);
        }

        sort(res.begin(), res.end());
        return res;
    }
};
