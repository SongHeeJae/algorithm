/*
위상정렬을 이용하여 풀 수 있었습니다.
선수과정부터 순차적으로 모든 과정을 탐색합니다.
특정 과정을 완료하는데 걸리는 최소 시간을 t[i]라고 한다면,
선수 과정이 없는 과정들의 t[i] = time[i]으로 초기화하고,
t[과정] = time[과정] + max(t[모든_선수과정]) 으로 구할 수 있습니다.
동시에 진행될 수 있는 모든 선수과정이 끝나야, 해당 과정을 수행할 수 있기 때문입니다.
*/

class Solution {
public:
    int ind[50000] = {0};
    int t[50000] = {0};
    vector<int> graph[50000];
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        for(auto& r : relations) {
            graph[r[0] - 1].push_back(r[1] - 1);
            ind[r[1] - 1]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(ind[i] == 0) {
                q.push(i);
                t[i] = time[i];
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int nxt : graph[node]) {
                t[nxt] = max(t[nxt], time[nxt] + t[node]);
                if(--ind[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        int res = 0;
        for(int i=0; i<n; i++) res = max(res, t[i]);
        return res;
    }
};
