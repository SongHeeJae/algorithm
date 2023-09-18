/*
BFS와 비트마스크를 이용하여 풀 수 있었습니다.
각 노드에 대한 최대 12개의 노드 방문 여부를 12개의 비트를 이용하여 나타내주었습니다.
*/

class Solution {
public:
    int v[4096][12] = {0};
    vector<int> g[12];
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        for(int i=0; i<n; i++) {
            for(int node : graph[i]) {
                g[node].push_back(i);
                g[i].push_back(node);
            }
        }

        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            q.push({i, 1 << i});
            v[1 << i][i] = 1;
        }

        while(!q.empty()) {
            int node = q.front().first;
            int visit = q.front().second;
            q.pop();

            if (visit == (1 << n) - 1) return v[visit][node] - 1;

            for(int nxt : g[node]) {
                int nvisit = visit | (1 << nxt);
                if(v[nvisit][nxt]) continue;
                v[nvisit][nxt] = v[visit][node] + 1;
                q.push({nxt, nvisit});
            }
        }

        return 0;
    }
};
