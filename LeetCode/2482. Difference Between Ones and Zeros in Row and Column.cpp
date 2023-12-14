/*
각 행과 열에서 1의 개수를 전처리해줍니다. (onesRow, onesCol)
각 행과 열의 0의 개수는 n과 m에서 1의 개수를 빼주면 됩니다. (zerosRow = n - onesRow, zerosCol = m - zerosCol)
이를 이용하여 diff[i][j]를 구해줍니다.
*/

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size();
        vector<int> numberOfOnesInRows(n, 0), numberOfOnesInCols(m, 0);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                numberOfOnesInRows[i] += grid[i][j];
                numberOfOnesInCols[j] += grid[i][j];
            }
        }

        vector<vector<int>> diff(n, vector<int>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int onesRow = numberOfOnesInRows[i];
                int zerosRow = n - numberOfOnesInRows[i];
                int onesCol = numberOfOnesInCols[j];
                int zerosCol = m - numberOfOnesInCols[j];
                diff[i][j] = onesRow + onesCol - zerosRow - zerosCol;
            }
        }
        return diff;
    }
};
