/*
다익스트라를 이용하여 풀 수 있었습니다.
*/

class Solution {
public:
    vector<pair<int, int>> graph[101];
    int d[101] = {0};
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(int i=1; i<=n; i++) {
            graph[i].clear();
            d[i] = INT_MAX;
        }
        d[k] = 0;
        
        for(auto& time : times)
            graph[time[0]].push_back({time[1], time[2]});
        
        priority_queue<pair<int, int>> pq;
        pq.push({0, k});
        while(!pq.empty()) {
            int x = pq.top().second;
            int c = -pq.top().first;
            pq.pop();
            
            if(d[x] < c) continue;
            
            for(auto& nxt : graph[x]) {
                int nx = nxt.first;
                int nc = c + nxt.second;
                if(d[nx] > nc) {
                    d[nx] = nc;
                    pq.push({-nc, nx});
                }
            }
        }
        
        int mx = 0;
        for(int i=1;i<=n; i++)
            mx = max(mx, d[i]);
        
        return mx == INT_MAX ? -1 : mx;
    }
};