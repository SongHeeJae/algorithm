/*
각 행과 열에서 1의 개수를 전처리해줍니다.
행렬의 숫자가 1일 때, 위치한 행과 열에서 1의 개수가 1개인지 확인해줍니다.
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat.front().size();

        vector<int> rows(n, 0), cols(m, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }
        
        int res = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                res += mat[i][j] && rows[i] == 1 && cols[j] == 1;
            }
        }
        return res;
    }
};
