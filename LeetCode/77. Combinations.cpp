/*
재귀를 이용하여 모든 조합을 찾아주었습니다.
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> arr;
        vector<int> temp;
        combine(arr, temp, n, k, 1);
        return arr;
    }

    void combine(vector<vector<int>>& arr, vector<int>& temp, int n, int k, int idx) {
        if (temp.size() == k) {
            arr.push_back(temp);
            return;
        }

        for(int i=idx; i<=n; i++) {
            temp.push_back(i);
            combine(arr, temp, n, k, i + 1);
            temp.pop_back();
        }
    }
};
