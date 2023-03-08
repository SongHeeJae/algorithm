/*
이진 탐색을 이용하여 풀 수 있었습니다.
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1000000000;
        while(l <= r) {
            int m = (l + r) / 2;
            if(chk(piles, h, m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r + 1;
    }

    bool chk(vector<int>& piles, int h, int k) {
        for(int pile : piles) {
            h -= pile / k + ((pile % k) != 0);
            if(h < 0) return false;
        }
        return true;
    }
};
