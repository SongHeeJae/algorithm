bool comp(pair<int,int>& a, pair<int,int>& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat.front().size();
        vector<pair<int, int>> rows;
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j = 0; j<m; j++) {
                cnt += mat[i][j];
            }
            rows.push_back({cnt, i});
        }
        
        sort(rows.begin(), rows.end(), comp);
        
        vector<int> res;
        for(int i=0; i<k; i++) {
            res.push_back(rows[i].second);
        }
        return res;
    }
};

/*
각 행마다 군인 수를 구해준 뒤, (군인 수 오름차순, 행 번호 오름차순)으로 정렬하였습니다.
k - 1번까지 응답해주면 됩니다.
*/