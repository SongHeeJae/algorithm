/*
특정한 두 점 사이의 변화량 cdx, cdy를 구해두고, 다른 두 점 사이의 변화량 dx, dy를 구해줍니다.
모두 동일한 기울기(dx * cdy == dy * cdx)를 가지는지 확인해줍니다.
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int dx = c[0][0] - c[1][0];
        int dy = c[0][1] - c[1][1];
        for(int i=2; i<c.size(); i++) {
            int cdx = c[i][0] - c[i - 1][0];
            int cdy = c[i][1] - c[i - 1][1];
            if(dx * cdy != dy * cdx) return false;
        }
        return true;
    }
};
