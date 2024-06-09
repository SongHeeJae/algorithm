/*
nums를 정렬하고, nums를 순회하며 x 가능 여부를 검사해줍니다.
각 인덱스에서 lower bound를 수행하면, 인덱스보다 크거나 같은 요소의 개수를 구할 수 있습니다.
*/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1; i<=nums.size(); i++) {
            int idx = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
            if(nums.size() - idx == i) return i;
        }
        return -1;
    }
};

/*
각 수의 개수와 누적합을 이용하여, nums.size()부터 x 가능 여부를 검사해줍니다.
큰 수부터 검사하며 누적합을 구해두면, 각 수보다 크거나 같은 요소의 개수를 구할 수 있습니다. 
*/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int cnt[1002] = {0}, n = nums.size();
        for(int num : nums) cnt[min(n, num)]++;
        for(int i = n; i>0; i--) {
            cnt[i] += cnt[i + 1];
            if(cnt[i] == i) return i;
        }
        return -1;
    }
};
