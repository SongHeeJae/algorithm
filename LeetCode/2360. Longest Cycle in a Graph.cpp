/*
DFS를 이용하여 풀었습니다.
특정 경로에서 노드를 재방문하게 된다면, 현재의 경로가 사이클이라는 것을 의미합니다.
사이클을 이루게 되었을 때, 해당 노드를 반환해줍니다.
반환된 노드가 경로를 되돌아가며 사이클의 시작점에 다시 도달한다면, 그 때까지 노드의 개수가 사이클을 이루는 노드의 개수입니다.
*/

class Solution {
public:
    bool visit[100000] = {false};

    int longestCycle(vector<int>& edges) {
        int res = -1;
        for(int i=0; i<edges.size(); i++) {
            if(visit[i]) continue;
            int cnt = 0;
            dfs(i, cnt, res, edges);
        }

        return res;
    }

    int dfs(int node, int& cnt, int& res, vector<int>& edges) {
        if(node == -1) return -1;
        if(visit[node]) return node;

        visit[node] = true;

        int val = dfs(edges[node], cnt, res, edges);

        if(val == -1) {
            return -1;
        } else if(val == node) {
            res = max(res, cnt + 1);
            return -1;
        } else {
            cnt++;
            return val; 
        }
    }
};
