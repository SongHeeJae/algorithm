/*
BFS를 이용하여 풀 수 있었습니다.
각 label을 2차원 좌표로 변환할 수 있도록 하고, 1에서 n*n에 도달할 때까지 수행해줍니다.
*/

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int v[401] = {0};

        queue<int> q;

        q.push(1);
        v[1] = 1;

        while(!q.empty()) {
            int label = q.front();
            q.pop();

            if(label == n * n) return v[label] - 1;
            
            for(int i=label + 1; i<=min(label + 6, n * n); i++) {
                pair<int, int> p = labelToPoint(n, i);
                int dst = board[p.first][p.second] != -1 ? board[p.first][p.second] : i;
                if(v[dst]) continue;
                v[dst] = v[label] + 1;
                q.push(dst);
            }
        }

        return -1;

    }

    pair<int, int> labelToPoint(int n, int label) {
        int x = n - (label - 1) / n - 1;
        int y = (n - x + 1) % 2 == 0 ? (label - 1) % n : n - (label - 1) % n - 1;
        return {x, y};
    }
};
