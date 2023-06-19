/*
합을 계속 누적해주고, 최댓값을 찾아줍니다.
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cnt = 0, res = 0;
        for(int g : gain) {
            cnt += g;
            res = max(res, cnt);
        }
        return res;
    }
};
