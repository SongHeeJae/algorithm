/*
x 좌표 기준으로 정렬해주고, 두 좌표 사이의 최대 width를 구해줍니다.
*/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int res = 0;
        for(int i=1; i<points.size(); i++) {
            res = max(res, points[i][0] - points[i - 1][0]);
        }
        return res;
    }
};

/*
set에 x좌표를 넣어주고 중복은 무시할 수도 있습니다.
*/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> xPoint;
        for(auto& p : points) xPoint.insert(p[0]);
        int res = 0, px = *xPoint.begin();
        for(int x : xPoint) {
            res = max(res, x - px);
            px = x;
        }
        return res;
    }
};
