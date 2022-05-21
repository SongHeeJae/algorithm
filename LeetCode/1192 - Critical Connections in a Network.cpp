/*
0번 노드를 기준으로 DFS를 수행하면서 방문하는 순서대로 번호를 붙여줍니다.
각 노드에서 이동할 수 있는 경로 내에 가장 작은 방문 번호를 구해서 반환해줄 것입니다.
이미 방문한 노드라면, 더 작은(먼저 방문한) 번호로 업데이트해줍니다.
아직 방문하지 않은 노드라면, 해당 노드가 반환하는 더 작은 번호로 업데이트해줍니다.
이 때, 아직 방문하지 않았던 노드에게 반환된 번호가 현재 방문 번호보다 크다면, 현재 경로를 거치지 않고서 해당 노드에 진입할 수 있는 우회로가 없음을 의미합니다.
즉, 네트워크를 분리하는 critical connection이 됩니다.
다른 경로가 있었다면, 현재 노드의 번호 이하(이미 방문했던 노드들)의 값이 반환될 것이기 때문입니다. 
*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> graph[100000];
    int id[100000] = { 0 };
    int num = 1;
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1);
        return ans;
    }
    
private:
    int dfs(int node, int prv) {
        int res = id[node] = num++;
        for (int nxt : graph[node]) {
            if(nxt == prv) continue;
            if(id[nxt]) res = min(res, id[nxt]);
            else {
                int ret = dfs(nxt, node);
                if(ret > id[node]) ans.push_back({nxt, node});
                res = min(res, ret);
            }
        }
        return res;
    }
};