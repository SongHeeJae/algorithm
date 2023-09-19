/*
상수 공간만 사용하고, nums를 수정하지 않는 방법으로는, 이진탐색을 이용하여 풀 수 있었습니다.
[1, n] 범위의 수를 이진탐색하며, 탐색되는 값 이하인 각 수의 개수를 구해줍니다.
개수가 탐색되는 값 이하라면, 해당 범위의 수에서는 중복이 없었음을 의미합니다.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        while(l < r) {
            int m = (l + r) / 2;
            
            int cnt = 0;
            for(int n : nums)
                if (n <= m) cnt++;

            if(cnt <= m) l = m + 1;
            else r = m;
        }
        return l;
    }
};


/*
O(n)의 추가 공간을 사용하여 O(1)의 시간으로 풀 수도 있었습니다.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int n : nums) {
            if(c[n]) return n;
            c[n] = 1;
        }
        return -1;
    }
};
