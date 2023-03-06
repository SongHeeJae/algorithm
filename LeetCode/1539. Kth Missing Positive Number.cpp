/*
arr을 순차적으로 탐색하면서 각 수 사이의 간극을 계산해주면, O(n) 시간에 k번 째 수를 알 수 있습니다.
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr.front() > k) return k;
        if(arr.back() < k) return k + arr.size();

        int i = 0, s = 0;
        for(int num : arr) {
            s += num - i - 1;
            if(s >= k) return num - (s - k + 1);
            i = num;
        }
        return arr.back() + k - s;
    }
};


/*
이진 탐색을 이용하여 로그 시간에도 풀 수 있었습니다.
누락되지 않았을 때의 arr[i] == i + 1이어야 하므로, 이를 이용하여 범위를 좁혀주었습니다. 
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr.front() > k) return k;
        if(arr.back() < k) return k + arr.size();

        int l = 0, r = arr.size() - 1;
        while(l <= r) {
            int m = (l + r) / 2;
            if(arr[m] - m <= k) l = m + 1;
            else r = m - 1;
        }
        return l + k;
    }
};
