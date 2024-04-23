/*
위상정렬을 이용하여 풀 수 있었습니다.
주어진 그래프는 양방향이므로, indegree가 1인 노드들부터 순회할 때, 마지막 순번의 노드들이 MHT의 root가 됩니다.
*/

class Solution {
public:
    vector<int> graph[20000];
    int ind[20000] = {0};

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        for(auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            ind[e[0]]++;
            ind[e[1]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(ind[i] == 1) {
                q.push(i);
            }
        }

        vector<int> res;
        while(!q.empty()) {
            res.clear();
            int sz = q.size();
            while(sz--) {
                int node = q.front(); q.pop();
                res.push_back(node);
                for(int nxt : graph[node]) {
                    if(--ind[nxt] == 1) {
                        q.push(nxt);
                    }
                }
            }
        }
        return res;
    }
};
