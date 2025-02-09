/*
https://leetcode.com/problems/xor-queries-of-a-subarray
prefix xor을 미리 전처리해두고, 각 쿼리를 빠르게 구할 수 있었습니다.
*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> x(arr.size() + 1);
        x[0] = 0;
        for(int i=0; i<arr.size(); i++) {
            x[i + 1] = x[i] ^ arr[i];
        }
        vector<int> res;
        for(vector<int>& query : queries) {
            int left = query[0];
            int right = query[1];
            res.push_back(x[right + 1] ^ x[left]);
        }
        return res;
    }
};
