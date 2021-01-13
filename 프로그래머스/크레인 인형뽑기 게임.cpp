#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, N = board.size();
    stack<int> basket;
    vector<int> board_len;
    for(int i=0; i<N; i++) {
        int len = 0;
        for(int j=N-1; j>=0 && board[j][i] != 0; j--) {
               len++;
        }
        board_len.push_back(len);
    }
    for(int i=0; i<moves.size(); i++) {
        int move = moves[i] - 1;
        if(board_len[move] <= 0) continue;
        int idx = N - (--board_len[move]) - 1;
        int doll = board[idx][move];
        if(!basket.empty() && doll == basket.top()) {
            basket.pop();
            answer+=2;
        } else {
            basket.push(doll);
        }
    }
    return answer;
}