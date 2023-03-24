/*
순방향은 1의 가중치, 역방향은 0의 가중치를 주면서 양방향 그래프를 만들어줍니다.
가중치는 주어진 개별 경로의 두 노드를, 각 방향으로 이동하는 비용을 의미합니다.
0에서 모든 노드를 방문할 수 있는 가중치를 구해줍니다.
*/

class Solution {
public:
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto& conn : connections) {
            graph[conn[0]].push_back({conn[1], 1});
            graph[conn[1]].push_back({conn[0], 0});
        }
        return dfs(0, -1, graph);
    }

    int dfs(int city, int prv, vector<vector<pair<int, int>>>& graph) {
        int cost = 0;
        for(auto& nxt : graph[city]) {
            if(nxt.first != prv) {
                cost += dfs(nxt.first, city, graph) + nxt.second;
            }
        }
        return cost;
    }
};
