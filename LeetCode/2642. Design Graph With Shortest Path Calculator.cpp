/*
다익스트라를 이용하여 풀 수 있었습니다.
간선이 추가될 수 있고 시작/출발점이 달라질 수 있음을 유의해야합니다.
노드 개수 n은 100이하, 간선은 n*(n-1)개 이하, shortestPath는 최대 100번까지 호출될 수 있습니다.
제한 조건을 확인해보니, 최소 비용을 요구할 때마다 heap을 이용하여 다익스트라를 구현해도, 제한 시간 내에 충분히 들어올 수 있었습니다.
addEdge에서는 그래프를 즉시 업데이트해주고, shortestPath에서는 다익스트라를 이용하여 최소 비용을 구해줍니다.
노드 개수 * 다익스트라 * 최대 호출 횟수 = n * (elog(n)) * 100
*/

class Graph {
public:
    int n;
    vector<vector<pair<int, int>>> graph;
    vector<int> dist;

    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        this->graph.resize(n);
        for(auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;

        priority_queue<pair<int, int>> pq;
        pq.push({0, node1});
        while(!pq.empty()) {
            int cost = -pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dist[node] < cost) continue;

            for(auto& nxt : graph[node]) {
                int nxtNode = nxt.first;
                int nxtCost = dist[node] + nxt.second;
                if(nxtCost < dist[nxtNode]) {
                    pq.push({-nxtCost, nxtNode});
                    dist[nxtNode] = nxtCost;
                }
            }
        }

        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};
