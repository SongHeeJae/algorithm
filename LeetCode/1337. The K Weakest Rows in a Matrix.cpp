/*
heap을 이용하여 조건에 부합하는 상위 k개의 행을 유지해줍니다.
*/

struct comp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

        for(int i=0; i<mat.size(); i++) {
            int cnt = 0;
            for(int j=0; j<mat[i].size() && mat[i][j]; j++) {
                cnt++;
            }

            pq.push({cnt, i});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> res(k);
        while(!pq.empty()) {
            res[--k] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};
