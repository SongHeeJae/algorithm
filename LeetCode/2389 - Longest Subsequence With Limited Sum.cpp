/*
subsequence의 합이 queries[i]보다 작거나 같은, subsequence의 최대 길이를 구해주어야합니다.
nums 배열을 오름차순으로 정렬해주고, 각 인덱스에서의 누적합을 구해줍니다.
인덱스 i에서의 누적합은 queries[i]보다 작거나 같은 subsequence의 길이를 의미합니다.
queries[i]보다 큰 값이 처음으로 나오는, 누적합 배열의 인덱스(subsequence의 최대 길이)를 구하기 위해 upperBound를 이용해줍니다.
upperBound 코드를 작성할 때에는,
마지막 요소가 타겟보다 크다면, 배열의 크기를 반환해줌으로써 subsequence의 길이를 구할 수 있도록 합니다.
*/

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        vector<int> res;
        for(int q : queries) {
            res.push_back(upperBound(nums, q));
        }
        return res;
    }
private:
    int upperBound(vector<int>& arr, int target) {
        if(arr.back() <= target) return arr.size();

        int s = 0, e = arr.size() - 1;
        while(s < e) {
            int m = (s + e) / 2;
            if(arr[m] > target) e = m;
            else s = m + 1;
        }

        return e;
    }
};
