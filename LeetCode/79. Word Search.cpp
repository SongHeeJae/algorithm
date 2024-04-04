/*
각 지점에서 word를 만들 수 있는지 dfs로 순회해줍니다.
*/

class Solution {
public:
    bool visit[6][6] = {false};
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(exist(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string& word, int x, int y, int idx) {
        if(idx == word.size()) return true;
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;
        if(board[x][y] != word[idx]) return false;
        if(visit[x][y]) return false;
        visit[x][y] = true;
        bool res = exist(board, word, x + 1, y, idx + 1)
            || exist(board, word, x - 1, y, idx + 1)
            || exist(board, word, x, y + 1, idx + 1)
            || exist(board, word, x, y - 1, idx + 1);
        visit[x][y] = false;
        return res;
    }
};
