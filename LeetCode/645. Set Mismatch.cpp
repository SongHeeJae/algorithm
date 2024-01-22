/*
1~N과 nums[0]~nums[i-1]을 모두 xor 연산해줍니다.
중복된 수가 a이고, 손실된 수가 b라면,
xor 연산 결과 = a ^ b가 됩니다.
nums에서 중복된 수 a를 찾아주면, b = a ^ b ^ b 연산으로 구할 수 있습니다.
nums에서 이미 발견된 수는 해당 인덱스를 음수로 기억해줌으로써 중복된 수를 찾아낼 수 있었습니다.
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int loss = 0;
        for(int i=0; i<nums.size(); i++) {
            loss ^= nums[i] ^ (i + 1);
        }

        for(int i=0; i<nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0) {
                nums[idx] = -nums[idx];
            } else {
                int num = idx + 1;
                return {num, loss ^ num};
            }
        }

        return {};
    }
};
