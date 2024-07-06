/*
arr에서 3개의 연속된 수가 홀수인지 확인해줍니다.
*/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] % 2) {
                if(++cnt == 3) return true;
            } else {
                cnt = 0;
            }
        }
        return false;
    }
};
