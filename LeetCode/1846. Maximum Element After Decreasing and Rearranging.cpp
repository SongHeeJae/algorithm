/*
arr을 오름차순으로 정렬해주고, 0번째 값을 1로 바꿔줍니다.
i(i > 0)번째 값부터는, arr[i] = min(arr[i], arr[i - 1] + 1).
arr[i]가 arr[i - 1] + 1보다 더 큰 값일 수 있다면, 차감 연산을 수행해줍니다.
*/

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for(int i=1; i<arr.size(); i++) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }
        return arr.back();
    }
};
