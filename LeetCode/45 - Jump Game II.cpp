/*
nums를 순차적으로 탐색하면서, 지금 지점에서 갈 수 있는 가장 먼 지점을 업데이트해줍니다.
이를 이용하여, 현재 지점에서 다음으로 도약할 수 있는 가장 먼 지점을 기억해줍니다.
현재 지점에서 해당 지점까지는 1번의 도약으로 갈 수 있음을 의미합니다.
해당 지점에 도달했다면, 다음으로 도약할 수 있는 가장 먼 지점을 다시 업데이트해줍니다.
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0, mx = 0, cur = 0;
        for(int i=0; i<nums.size() - 1 && cur < nums.size() - 1; i++) {
            mx = max(mx, i + nums[i]);
            if(cur == i) {
                cur = mx;
                cnt++;
            }
        }
        
        return cnt;
    }
};
