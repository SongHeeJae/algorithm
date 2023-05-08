/*
각 대각선의 합을 구해줍니다. 매트릭스의 길이가 홀수일 때에는, 중앙에 있는 값을 차감해줍니다.
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int s = n % 2 ? -mat[n/2][n/2] : 0;
        for(int i=0; i<n; i++) {
            s += mat[i][i] + mat[i][n - i - 1];
        }
        return s;
    }
};
