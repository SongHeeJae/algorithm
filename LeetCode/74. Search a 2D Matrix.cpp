/*
주어진 2D Matrix는 두 조건에 의해 오름차순으로 만들어져있습니다.
2차원 배열을 오름차순으로 정렬된 1차원 배열로 보고, 이진탐색을 수행해줍니다.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix.front().size();
        int l = 0, r = n * m - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int val = matrix[mid / m][mid % m];
            if(val == target) return true;
            else if(val > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};
