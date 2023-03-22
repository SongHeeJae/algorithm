/*
BFS로 풀었습니다.
1번 도시에서 모든 도시를 순회하면서, 연결된 간선 중에서 minimum score를 찾아주면 됩니다.
*/

class Solution {
public:
    vector<pair<int, int>> graph[100001];
    bool visit[100001] = {false};

    int minScore(int n, vector<vector<int>>& roads) {
        for(auto& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        int res = INT_MAX;
        queue<int> q;
        q.push(1);
        visit[1] = true;

        while(!q.empty()) {
            int city = q.front();
            q.pop();

            for(auto& nxt : graph[city]) {
                int nxtCity = nxt.first;
                int nxtScore = nxt.second;
                res = min(res, nxtScore);
                if(visit[nxtCity]) continue;
                visit[nxtCity] = true;
                q.push(nxtCity);
            }
        }
        return res;
    }
};
