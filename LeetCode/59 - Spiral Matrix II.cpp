/*
좌측상단에서 시작하여 나선형으로 회전하며 숫자를 채워주었습니다.
방향이 좌에서 상으로 회전될 때는 가로의 깊이를,
방향이 상에서 우로 회전될 때는 세로의 깊이를 하나씩 올려주며, 회전해야할 위치를 감지해주었습니다.
*/

class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int x = 0, y = 0, d = 0, val = 1, wDepth = 0, hDepth = 0;
        while(val <= n * n) {
            matrix[x][y] = val++;
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < wDepth || ny < hDepth || nx >= n - wDepth || ny >= n - hDepth) {
                d = (d + 1) % 4;
                nx = x + dx[d];
                ny = y + dy[d];
                wDepth += d == 3;
                hDepth += d == 0;
            }
            x = nx;
            y = ny;
        }
        return matrix;
    }
};