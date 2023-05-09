/*
이미 탐색한 행과 열의 범위를 좁히고 방향을 바꿔가면서, 나선형으로 공간을 방문해줍니다.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int l = 0, r = matrix.front().size() - 1, u = 0, d = matrix.size() - 1, dir = 0;
       vector<int> res;
       while(l <= r && u <= d) {
           if(dir == 0) {
               for(int i=l; i<=r; i++) res.push_back(matrix[u][i]);
               u++;
           } else if(dir == 1) {
               for(int i=u; i<=d; i++) res.push_back(matrix[i][r]);
               r--;
           } else if(dir == 2) {
               for(int i=r; i>=l; i--) res.push_back(matrix[d][i]);
               d--;
           } else {
               for(int i=d; i>=u; i--) res.push_back(matrix[i][l]);
               l++;
           }
           dir = (dir + 1) % 4;
       } 
       return res;
    }
};
