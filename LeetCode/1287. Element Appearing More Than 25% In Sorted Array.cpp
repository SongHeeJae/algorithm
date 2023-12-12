/*
배열은 오름차순으로 정렬되어있기 때문에, 25% 이상 등장하는 수의 길이를 구해두고, 해당 길이의 시작과 끝이 동일한 수인지 확인해줍니다.
*/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int t = arr.size() / 4;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] == arr[i + t]) return arr[i];
        }
        return -1;
    }
};

/*
이진탐색을 이용하여 로그 시간에 풀 수도 있습니다.
special integer의 후보군이 되는 수는 arr[n / 4], arr[n * 2 / 4], arr[n * 3 / 4]가 됩니다.
lower bound와 upper bound로 각 수의 시작과 끝 지점을 찾고, 25% 이상 등장하는지 확인해줍니다.
*/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if(isSpecialInteger(arr, arr.size() / 4)) return arr[arr.size() / 4];
        if(isSpecialInteger(arr, arr.size() / 2)) return arr[arr.size() / 2];
        return arr[arr.size() * 3 / 4];
    }

    bool isSpecialInteger(vector<int>& arr, int idx) {
        int diff = upper_bound(arr.begin(), arr.end(), arr[idx]) - lower_bound(arr.begin(), arr.end(), arr[idx]);
        return diff * 4 > arr.size();
    }
};
