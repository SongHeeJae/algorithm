/*
현재 부분적으로 채워진 상태가 스도쿠 조건을 충족하는지 확인하면 되었습니다.
각 행, 열, 3*3 박스마다 이미 사용된 숫자인지 기억하고, 검사해주었습니다.
*/

class Solution {
public:
    bool vRow[9][10], vCol[9][10], vBox[9][10];
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') continue;
                int val = board[i][j] - '0';
                int boxNumber = (i / 3 * 3) + j / 3;
                if(vRow[i][val] || vCol[j][val] || vBox[boxNumber][val]) return false;
                vRow[i][val] = vCol[j][val] = vBox[boxNumber][val] = true;
            }
        }
        return true;
    }
};