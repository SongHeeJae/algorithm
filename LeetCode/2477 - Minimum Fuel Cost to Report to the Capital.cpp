/*
DFS를 이용하여 풀 수 있었습니다.
0번 도시에서부터 모든 도시를 방문하고 돌아오면서, 방문했던 도시의 개수(각 도시에서 0번 도시로 향하면서 거친 도시의 개수)를 기억해줍니다.
각 도시에서 거쳐온 도시와 좌석의 개수를 이용하여, 다음 도시로 이동하는데 필요한 연료의 리터 수를 구해줍니다.
DFS 수행 이후, 0번 도시가 도착 지점이므로, 0번 도시에서 다음 도시로 이동하기 위해 필요했던 리터 수는 제외해줍니다.
*/

class Solution {
public:
    vector<int> graph[100001];
    long long res = 0;

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        for(auto& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        dfs(0, seats, -1);
        return res - (roads.size() + seats) / seats;
    }

    int dfs(int node, int seats, int prv) {
        int cnt = 1;
        for(int nxt : graph[node]) {
            if(nxt != prv)
                cnt += dfs(nxt, seats, node);
        }

        res += (cnt + seats - 1) / seats;

        return cnt;
    }
};
