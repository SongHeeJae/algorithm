/*
기울기를 이용하여 풀 수 있었습니다.
각 점과 모든 점 사이의 기울기를 구해줍니다.
동일한 기울기를 가진다면, 같은 직선 내에 있음을 의미합니다.
O(n^2)의 시간이 걸리지만, points의 개수가 최대 300개이기 때문에, 짧은 시간 내에 처리할 수 있습니다.
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i=0 ;i<points.size()-1; i++) {
            vector<int>& p1 = points[i];
            map<double, int> mCnt;
            for(int j=0; j<points.size(); j++) {
                if(i == j) continue;
                vector<int>& p2 = points[j];
                double m = (double)(p1[0] - p2[0]) / (p1[1] - p2[1]);
                mCnt[m]++;
            }
            for(auto& p : mCnt) {
                res = max(res, p.second);
            }
        }
        return res + 1;
    }
};

