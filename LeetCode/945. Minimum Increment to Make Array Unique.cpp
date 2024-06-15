/*
nums를 정렬하고, 동일한 수가 연속해서 나타나면 queue에 임시로 넣어줍니다.
nums[i]와 nums[i - 1] 사이에 2 이상의 간격이 나타나면, 해당 간격에 queue에 임시로 넣었던 값들을 채워줍니다.
O(nlogn)에 풀 수 있었습니다.
*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        queue<int> q;
        int prev = nums[0];
        int res = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == prev) {
                q.push(nums[i]);
            } else {
                for(int val = prev + 1; !q.empty() && val < nums[i]; val++) {
                    res += val - q.front();
                    q.pop();
                }
            }
            prev = nums[i];
        }

        while(!q.empty()) {
            res += ++prev - q.front();
            q.pop();
        }
        return res;
    }
};

/*
다음과 같이 개선할 수 있었습니다.
값이 증가해야하는 최소 기준점을 찾고, 그 수부터 1씩 올라가야합니다.
*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = nums[0] + 1, res = 0;
        for(int i=1; i<nums.size(); i++) {
            if (start < nums[i]) start = nums[i] + 1;
            else res += start++ - nums[i];
        }
        return res;
    }
};
