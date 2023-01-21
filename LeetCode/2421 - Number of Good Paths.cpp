/*
유니온 파인드를 이용하여 풀 수 있었습니다.
시작/출발점이 될 수 있는 동일한 값들을 그루핑해주고, 큰 값에서 작은 값으로 이동 가능한 방향 그래프를 구해줍니다.
가장 값이 작은 노드들부터 연결해주고, 각 연결된 그룹의 노드 개수를 구해줍니다.
새롭게 연결하는 노드 x개가 같은 그룹에 연결된다면, x * (x - 1) / 2개의 새로운 경로가 만들어지게 됩니다.
단일 노드도 유효한 경로이므로, 노드의 개수를 경로의 개수에 더해주면 됩니다.
*/

class Solution {
public:
    vector<int> graph[100001];
    int res = 0;
    int p[100001];

    map<int, vector<int>> sameValues;

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        memset(p, -1, sizeof(p));
        
        for(int i=0; i<vals.size(); i++) {
            sameValues[vals[i]].push_back(i);
        }

        for(auto& edge : edges) {
            if (vals[edge[0]] >= vals[edge[1]]) {
                graph[edge[0]].push_back(edge[1]);
            } else {
                graph[edge[1]].push_back(edge[0]);
            }
        }

        int res = vals.size();
        for(auto& [val, nodes] : sameValues) {
            for(int v : nodes) {
                for(int n : graph[v]) {
                    int x1 = find(v);
                    int x2 = find(n);
                    if(x1 != x2)
                        p[x1] = x2;
                }
            }

            map<int, int> cnt;
            for(int v : nodes) {
                cnt[find(v)]++;
            }

            for(auto& [i, c] : cnt) {
                res += c * (c - 1) / 2;
            }
        }


        return res;
    }

private:
    int find(int x) {
        if(p[x] == -1) return x;
        return p[x] = find(p[x]);
    }
};
