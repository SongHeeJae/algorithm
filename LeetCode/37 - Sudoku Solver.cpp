/*
각 행, 열, 3*3 박스 마다 이미 숫자가 사용된 상태를 기억해주었습니다.
이를 이용하면, 각 칸에 해당 숫자가 입력될 수 있는지 즉시 확인할 수 있습니다.
먼저 초기에 숫자가 사용된 상태를 구해주고, 각 칸을 채워나가며 상태를 업데이트 해줍니다. 
모든 칸을 채울 수 있었으면, 재귀를 빠져나오게 됩니다.

스도쿠에 나타난 9개의 3*3 박스는, 좌측 상단부터 우측 하단으로 향하며 0~8의 번호를 붙여주었습니다.
*/

class Solution {
public:
    bool vRow[9][10], vCol[9][10], vBox[9][10];
    
    void solveSudoku(vector<vector<char>>& board) {
        init(board);
        solve(board, 0, 0);
    }
    
    void init(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') continue;
                int val = board[i][j] - '0';
                int bn = getBoxNumber(i, j);
                vRow[i][val] = vCol[j][val] = vBox[bn][val] = true;  
            }
        }
    }
    
    bool solve(vector<vector<char>>& board, int x, int y) {
        if(x == 9) return true;
        
        int ny = y == 8 ? 0 : y + 1;
        int nx = x + (ny == 0);
        
        if(board[x][y] != '.') return solve(board, nx, ny);

        for(int i=1; i<10; i++) {
            int bn = getBoxNumber(x, y);
            if(vRow[x][i] || vCol[y][i] || vBox[bn][i]) continue;
            board[x][y] = i + '0';
            vRow[x][i] = vCol[y][i] = vBox[bn][i] = true;
            if(solve(board, nx, ny)) return true;
            vRow[x][i] = vCol[y][i] = vBox[bn][i] = false;
            board[x][y] = '.';
        }
        return false;
    }
    
    int getBoxNumber(int x, int y) {
        return (x / 3 * 3) + y / 3;
    }
};