/*
BFS를 이용하여 풀 수 있었습니다.
현재 노드에서 다음 노드로 넘어갈 때의 방문 비용보다, 이미 다음 노드의 방문 비용이 더 크다면,
다음 노드의 방문 비용을 업데이트해주면서 방문할 수 있도록 합니다.
k + 1 번 만큼 다음 영역으로 나아갈 수 있도록 합니다.
*/

class Solution {
public:
    vector<pair<int, int>> graph[100];
    int d[100];

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(int i=0; i<n; i++) {
            d[i] = INT_MAX;
        }

        for(auto& f : flights) {
            graph[f[0]].push_back({f[1], f[2]});
        }
        
        queue<pair<int, int>> q;

        q.push({src, 0});
        d[src] = 0;

        int cnt = 0;
        while(!q.empty() && cnt <= k) {
            int sz = q.size();
            while(sz--) {
                int node = q.front().first;
                int dist = q.front().second;
                q.pop();
                
                for(auto& nxt : graph[node]) {   
                    int nxtNode = nxt.first;
                    int nxtDist = dist + nxt.second;
                    if(nxtDist < d[nxtNode]) {
                        d[nxtNode] = nxtDist;
                        q.push({nxtNode, nxtDist});
                    }
                }
            }
            cnt++;
        }

        return d[dst] == INT_MAX ? -1 : d[dst];
    }
};
