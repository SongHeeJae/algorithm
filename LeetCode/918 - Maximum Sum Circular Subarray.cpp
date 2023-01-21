/*
카데인 알고리즘을 이용하여 풀 수 있었습니다.
가장 큰 합을 가지는 subarray 합을 구해줍니다.
circular subarray도 허용되기 때문에, 가장 작은 합을 가지는 subarray 합도 구해주겠습니다.
nums에서 가장 작은 합을 가지는 subarray를 제외해주면, 가장 큰 합을 가지는 circular subarray 합도 같이 판별할 수 있습니다.

즉, max(가장 큰 합을 가지는 subarray 합, nums 총합 - 가장 작은 합을 가지는 subarray 합)을 구해주면 됩니다.
예외 케이스가 있는데, nums가 모두 음수인 상황입니다.
이 경우에 (nums 총합 - 가장 작은 합을 가지는 subarray 합)이 0이되기 때문에, 가장 큰 합을 가지는 subarray 합을 반환해주면 됩니다.
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int s = 0;
        int cmx = 0, mx = INT_MIN;
        int cmn = 0, mn = INT_MAX;
        for(int num : nums) {
            cmx = max(num, cmx + num);
            mx = max(mx, cmx);
            cmn = min(num, cmn + num);
            mn = min(mn, cmn);
            s += num;
        }
        return mn == s ? mx : max(mx, s - mn);
    }
};
