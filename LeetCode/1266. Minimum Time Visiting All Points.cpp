/*
현 좌표와 전 좌표의 x 변화량, y 변화량을 구해줍니다.
대각선 이동, 수평 또는 수직 이동 모두 동일하게 1초 걸리기 때문에, 더 큰 변화량이 최소 이동 시간이 됩니다.
*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i=1; i<points.size(); i++) {
            int px = points[i - 1][0];
            int py = points[i - 1][1];
            int cx = points[i][0];
            int cy = points[i][1];

            int dx = abs(px - cx);
            int dy = abs(py - cy);
            
            res += max(dx, dy);
        }
        return res;
    }
    
};
