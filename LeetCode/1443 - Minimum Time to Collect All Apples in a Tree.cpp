/*
0번부터 모든 노드를 탐색하면서, 사과가 있는 경로에 속한 모든 노드에 대해서만 시간을 구해주면 됩니다.
지금 가는 경로의 가장 끝에서 사과를 발견했었다면, 돌아오는 경로는 노드 1개 당 2초의 시간이 걸리게 됩니다.
*/

class Solution {
public:
    vector<int> graph[100000];

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, hasApple);
    }

    int dfs(int node, int prv, vector<bool>& hasApple) {
        int res = 0;
        for(int nxt : graph[node]) {
            if(nxt == prv) continue;
            int val = dfs(nxt, node, hasApple);
            if(hasApple[nxt] || val) {
                res += val + 2;
            }
        }
        return res;
    }
};
