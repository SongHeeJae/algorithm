class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if(i >= 0) {
            int j = nums.size() - 1;
            while(nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

/*
추가 공간을 사용하지 못하는 조건이 있었습니다.
c++의 next permutation을 이용해도 되지만, 직접 구현해보려다 마땅한 풀이가 떠오르지 않아서 해설을 참조하였습니다.
뒤에서부터 검사하며 오름차순이 끊기는 지점을 찾아줍니다.
해당 지점의 좌측 수들은, 현재 순서를 유지할 수 있습니다.
다시 검사하며 해당 지점의 수보다 큰 값을 찾아서 스왑해줍니다.
남은 수는 오름차순으로 정렬하면, next permutation을 구할 수 있습니다.
검사해온 우측의 수들은 이미 오름차순으로 판별되어있기 때문에, 단순히 뒤집어주기만해도 정렬된 순서를 구할 수 있을 것입니다.
*/