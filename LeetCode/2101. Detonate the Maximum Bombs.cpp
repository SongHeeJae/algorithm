/*
폭탄 범위를 이용하여 그래프를 만들어주고, 각 경로에서의 폭탄 개수를 구해주었습니다.
*/

typedef long long ll;

class Solution {
public:
    vector<int> graph[100];
    bool visit[100] = {false};

    int maximumDetonation(vector<vector<int>>& bombs) {
        for(int i=0; i<bombs.size(); i++) {
            for(int j = 0; j<bombs.size(); j++) {
                if(i == j) continue;
                if(isConnected(bombs[i], bombs[j])) {
                    graph[i].push_back(j);
                }
            }
        }

        int res = 0;
        for(int i=0; i<bombs.size(); i++) {
            memset(visit, false, sizeof(visit));
            res = max(res, dfs(i));
        }
        
        return res;
    }

    int dfs(int idx) {
        if(visit[idx]) return 0;
        visit[idx] = true;
        int c = 1;
        for(int nxt : graph[idx])
            c += dfs(nxt);
        return c;
    }

    bool isConnected(vector<int>& a, vector<int>& b) {
        ll w = a[0] - b[0];
        ll h = a[1] - b[1];
        ll d = w * w + h * h;
        ll r = (ll)a[2] * a[2];
        return d <= r;
    }
};
