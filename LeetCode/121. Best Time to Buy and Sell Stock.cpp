/*
prices를 순차적으로 탐색하며 최소 가격을 기억해줍니다.
현재 가격과 지난 날들의 최소 가격 차이가 최대가 되는 액수를 구해줍니다.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX;
        int res = 0;
        for(int p : prices) {
            res = max(res, p - mn);
            mn = min(mn, p);
        }
        return res;
    }
};
