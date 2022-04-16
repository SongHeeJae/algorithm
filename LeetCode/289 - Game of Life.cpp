/*
각 셀마다 8방향을 검사하며 죽거나 살게될 셀들을 기억해주었습니다.
모든 셀을 검사한 뒤, 보드를 업데이트해주었습니다.
*/

class Solution {
public:
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,1,0,-1,1,-1,1,0};
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> fliped;
        int n = board.size();
        int m = board.front().size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int c = countLiveCell(board, i, j);
                if(board[i][j]) {
                    if(c < 2 || c > 3) fliped.push_back({i, j});
                } else {
                    if(c == 3) fliped.push_back({i, j});
                }
            }
        }
        
        for(pair<int, int>& p : fliped) {
            board[p.first][p.second] = !board[p.first][p.second];
        }
    }
    
    int countLiveCell(vector<vector<int>>& board, int x, int y) {
        int count = 0;
        for(int i=0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board.front().size()) continue;
            count += board[nx][ny];
        }
        return count;
    }
};

/*
하단 부에 적힌 다음 조건을 적용해봤습니다.
Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
위 문장에서는, 다음과 같이 두 가지 조건을 도출할 수 있었습니다.
- in-place
- 동시에 업데이트되어야 한다. 처음 연산된 결과를 가지고 나중에 다시 업데이트해서는 안된다.
다른 사람들은 어떻게 풀었는지 찾아보니,
in-place를 만족하는 코드는 많았지만,
두번째 조건까지 동시에 만족하는 코드는 찾아볼 수 없었습니다.
제 해석의 문제인지, 제가 개념적으로 잘못이해하고 있는건지는 모르겠지만, 일단 저는 다음과 같이 풀어봤습니다.
*/


class Solution {
public:
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,1,0,-1,1,-1,1,0};
    
    void gameOfLife(vector<vector<int>>& board) {
        nextState(board, 0, 0);
    }
    
    void nextState(vector<vector<int>>& board, int x, int y) {
        if(x == board.size()) return;
        
        int c = countLiveCell(board, x, y);
        
        int nx = y == board.front().size() - 1 ? x + 1 : x;
        int ny = y == board.front().size() - 1 ? 0 : y + 1;
        nextState(board, nx, ny);
        
        board[x][y] = board[x][y] ? 2 <= c && c <= 3 : c == 3;
    }
    
    int countLiveCell(vector<vector<int>>& board, int x, int y) {
        int count = 0;
        for(int i=0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board.front().size()) continue;
            count += board[nx][ny];
        }
        return count;
    }
};


/*
그런데 한 가지 의문점은,
이렇게 재귀를 이용하면 스택 프레임이 쌓이는데,
꼬리 재귀처럼 컴파일러가 최적화해 줄 여지도 없는 위 코드를 in-place라고 볼 수 있을지 애매했습니다.
https://cstheory.stackexchange.com/questions/9563/all-recursive-algorithms-are-inherently-not-inplace-isnt-it
찾아보니 이런 내용이 있었습니다.
결국 이러한 코드도 O(n*m)의 스택 공간을 가지게 되므로 in-place는 아니라고 보는게 타당할 것 같습니다.
그렇다면, 저 두 가지 조건을 만족시키려면 어떤 식으로 코드를 작성할 수 있는건지 궁금합니다.

사실 in-place가 뭔지 몰라서 조금 더 찾아봤는데,
https://en.wikipedia.org/wiki/In-place_algorithm 를 확인해보니,
퀵 정렬의 경우도 O(logN)의 스택 공간을 가지지만 in-place로 취급한다고 합니다.

그러면, 위 문제도 O(n*m) 미만의 스택 공간 * 추가 공간을 가지게 하면 in-place로 취급되는 건지 의문이 남습니다. (어떻게 하는진 모름)
애초에 처음 연산된 결과를 가지고 나중에 다시 업데이트해서는 안된다는 조건을 가지고 풀 수 있는 건지 잘 모르겠습니다.
두 조건을 동시에 만족시키기는 어려워보이는데, 아마 제가 해석을 잘못한 것 같기도 합니다.


아무튼, in-place만 만족하게 풀려면 다음과 같이 풀이할 수 있었습니다.
살아있다가 죽은 것, 죽어있다가 살은 것을 구분해주면 됩니다.
*/

class Solution {
public:
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,1,0,-1,1,-1,1,0};
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board.front().size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int c = countLiveCell(board, i, j);
                if(board[i][j]) {
                    if(c < 2 || c > 3) board[i][j] = 2; // 살아있다가 죽은 것
                } else {
                    if(c == 3) board[i][j] = -1; // 죽어있다가 살아난 것
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 2) board[i][j] = 0;
                else if(board[i][j] == -1) board[i][j] = 1;
            }
        }
    }
    
    int countLiveCell(vector<vector<int>>& board, int x, int y) {
        int count = 0;
        for(int i=0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board.front().size()) continue;
            count += board[nx][ny] > 0;
        }
        return count;
    }
};