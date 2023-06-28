/*
다익스트라를 이용하여 풀 수 있었습니다.
시작 지점은 1의 확률로, 방문되지 않은 지점은 0의 확률로 초기화하고, 각 노드에 도달하는 확률을 구해줍니다.
*/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> d(n, 0);
        d[start] = 1;
        priority_queue<pair<double, int>> pq;
        pq.push({1, start});

        while(!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(prob > d[node]) continue;

            for(pair<int, double> nxt : graph[node]) {
                int nxtNode = nxt.first;
                double nxtProb = prob * nxt.second;
                if(d[nxtNode] < nxtProb) {
                    pq.push({nxtProb, nxtNode});
                    d[nxtNode] = nxtProb;
                }
            }
        }

        return d[end];
    }
};
