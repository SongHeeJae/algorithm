/*
현재 구간과 이전 구간에서의 연속된 1의 개수를 구해줍니다. 이 개수를 더하여 결과를 구해주면 됩니다.
결과가 nums의 길이와 동일하다면, 하나는 무조건 삭제해야하기 때문에, 1을 삭제해야합니다.
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0, prvCnt = 0, res = 0;
        for(int n : nums) {
            if(n) {
                cnt++;
            } else {
                res = max(res, cnt + prvCnt);
                prvCnt = cnt;
                cnt = 0;
            }
        }
        res = max(res, cnt + prvCnt);
        return res - (res == nums.size());
    }
};

