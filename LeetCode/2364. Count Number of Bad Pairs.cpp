/*
https://leetcode.com/problems/count-number-of-bad-pairs/
j - i != nums[j] - nums[i] 조건을 이항해보면,
nums[i] - i != nums[j] - j로 바꿔볼 수 있습니다.
nums를 순회하면서, nums[i] - i의 카운트를 해시 테이블에 기억해줍니다.
bad pair의 (i, j) 쌍은 i < j를 만족해야 하는데,
순회하는 인덱스 i는 이미 항상 i < j를 만족하고 있는 j라고 볼 수 있습니다.
현재 순회하는 i - (nums[i] - i의 카운트)를 구해주면, j까지의 모든 bad pair는 상수 시간에 구해집니다.
따라서, O(N)의 시간으로 풀 수 있었습니다.
1 <= nums[i] <= 10^9이므로, 카운트는 unordered_map에 저장해줬습니다.
*/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        long long res = 0;
        for(int i=0; i<nums.size(); i++)
            res += i - m[nums[i] - i]++;
        return res;
    }
};
