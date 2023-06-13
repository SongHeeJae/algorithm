/*
동일한 행의 개수를 미리 초기화해두고, 각 열에 대해 동일한 행의 개수를 찾아줍니다.
*/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> rows;
        for(int i=0; i<n; i++) {
            rows[grid[i]]++;
        }

        int res = 0;
        for(int i=0; i<n; i++) {
            vector<int> t;
            for(int j=0; j<n; j++) t.push_back(grid[j][i]);
            res += rows[t];
        }
        return res;
    }
};
