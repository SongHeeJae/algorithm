/*
nums[i]가 1이라면 1을, 0이라면 -1을 변수에 더해줍니다.
그리고 각 합에 대한 인덱스를 map에 기억해줍니다.
이후에 순회하면서 해당 합을 다시 가지게 된다면, 현재 인덱스와 이전에 합을 가진 인덱스의 차이를 구해주면 됩니다.
그 차이는 인덱스 사이에 있는 배열 요소 합이 0이 되는 것이므로, 0과 1이 동일한 개수를 가지고 있는 것을 의미합니다. 
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, res = 0;
        unordered_map<int, int> sumToIdxMap = {{0, -1}};
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i] ? 1 : -1;
            auto f = sumToIdxMap.find(sum);
            if(f != sumToIdxMap.end()) {
                res = max(res, i - f->second);
            } else {
                sumToIdxMap[sum] = i;
            }
        }
        return res;
    }
};
