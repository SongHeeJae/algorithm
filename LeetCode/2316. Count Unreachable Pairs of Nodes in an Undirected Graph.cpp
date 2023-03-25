/*
n개의 노드가 직접적으로 연결될 때의 간선의 개수는, (n * (n - 1)) / 2개가 됩니다.
노드 그래프에서, 간접적으로 연결되어있는 그룹의 노드 개수를 구하고, 해당 그룹의 모든 노드가 직접적으로 연결될 때의 간선의 개수를 제거해주면 됩니다.
그러면, 연결되지 않은 간선의 개수만 남게 됩니다.
*/

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visit(n, false);
        long long res = ((long long)n * (n - 1)) / 2;
        for(int i=0; i<n; i++) {
            if(!visit[i]) {
                int cnt = dfs(i, graph, visit);
                res -= ((long long)cnt * (cnt - 1)) / 2;
            }
        }
        
        return res;
    }

    int dfs(int node, vector<vector<int>>& graph, vector<bool>& visit) {
        if(visit[node]) return 0;
        visit[node] = true;
        int c = 1;
        for(int nxt : graph[node])
            c += dfs(nxt, graph, visit);
        return c;
    }
};

/*
그룹별 노드의 개수를 구해준 뒤, 연결되지 못하는 간선의 개수를 계산해줘도 됩니다.
*/

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> groupCount;
        vector<bool> visit(n, false);
        long long s = 0;
        for(int i=0; i<n; i++) {
            if(!visit[i]) {
                int cnt = dfs(i, graph, visit);
                groupCount.push_back(cnt);
                s += cnt;
            }
        }
        
        long long res = 0;
        for(int cnt : groupCount) {
            s -= cnt;
            res += s * cnt;
        }
        return res;
    }

    int dfs(int node, vector<vector<int>>& graph, vector<bool>& visit) {
        if(visit[node]) return 0;
        visit[node] = true;
        int c = 1;
        for(int nxt : graph[node])
            c += dfs(nxt, graph, visit);
        return c;
    }
};
