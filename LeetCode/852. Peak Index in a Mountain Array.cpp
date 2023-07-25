/*
이진탐색을 이용하여 로그 시간에 찾을 수 있었습니다.
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(arr[m] < arr[m + 1]) {
                l = m + 1;
            } else {
                r = m;
            }
        } 
        return l;
    }
};
