#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int solution(vector<vector<int>> board)
{
    int m = board[0][0];
    for(int i=1; i<board.size(); i++) {
        for(int j=1; j<board[0].size(); j++) {
            if(board[i][j]) {
                board[i][j] = min({board[i-1][j], board[i][j-1], board[i-1][j-1]}) + 1;
                m = max(m, board[i][j]);
            }
        }
    }
    return m * m;
}

/*
1로 이루어진 칸이면,
좌, 상, 좌상의 값 중 최솟값 + 1이 현재 칸까지의 최대 정사각형 길이가 됩니다.
*/