/*
N개의 노드를 연결하려면, 적어도 N-1개의 간선은 있어야합니다.
독립된 네트워크 그룹이 x개 있다면, x - 1개의 간선으로 모든 그룹을 연결할 수 있습니다.
*/

class Solution {
public:
    vector<int> graph[100000];
    bool visit[100000] = {false};

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        
        for(auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        
        int connectedGroupCount = 0;
        for(int i=0; i<n; i++) {
            if(!visit[i]) {
                dfs(i);
                connectedGroupCount++;
            }
        }

        return connectedGroupCount - 1;
    }

    void dfs(int computer) {
        visit[computer] = true;
        for(int nxt : graph[computer]) {
            if(!visit[nxt]) dfs(nxt);
        }
    }
};
