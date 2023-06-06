/*
O(n)의 시간과 O(n)의 공간으로 풀 수 있었습니다.
arr에서 최댓값 mx와 최솟값 mn을 구해주면, (mx - mn) / (arr.size() - 1)이 연이은 두 배열의 요소가 가져야하는 차이 diff임을 알 수 있습니다.
이 diff가 0으로 나누어떨어지지 않는다면, 연이은 두 배열의 요소가 동일한 diff를 가질 수 없게 되므로 false를 반환해줍니다.
이 diff가 0이라면, mx와 mn이 동일한 것이고, 모든 수가 동일한 것을 의미하므로 true를 반환해줍니다.
그렇지 않다면, 각 수가 정렬된 상태에서 원래 가져야하는 인덱스 (arr[i] - mn) / diff를 구해줍니다.
arr을 탐색하면서 각 수의 인덱스를 unordered_set에 저장해주고, 이미 저장던 인덱스가 다시 나타나면 모순되므로 false를 반환합니다.
*/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int mx = arr[0], mn = arr[0];
        for(int i=1; i<arr.size(); i++) {
            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);
        }

        if(((mx - mn) % (arr.size() - 1)) != 0) return false;

        int diff = (mx - mn) / (arr.size() - 1);
        if(diff == 0) return true;

        unordered_set<int> s;
        for(int i=0; i<arr.size(); i++) {
            int idx = (arr[i] - mn) / diff;
            if(s.find(idx) != s.end()) return false;
            s.insert(idx);
        }
        return true;
    }
};



/*
다음과 같이 O(n)의 시간과 O(1)의 공간으로 풀 수도 있었습니다.
arr을 탐색하면서, arr[i]가 인덱스에 맞는 수(mn + i * diff)라면 그대로 지나가줍니다.
arr[i]가 원래 가져야하는 인덱스 idx = (arr[i] - mn) / diff를 구해줍니다.
idx가 0으로 나누어 떨어지지 않는다면, false를 반환해줍니다.
arr[idx] == arr[i]라면, 위 수는 인덱스에 맞는 수여야했으므로 false를 반환해줍니다.
arr[i]를 원래 가져야하는 위치로 스왑해주고, 다시 검사를 수행해줍니다.
*/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int mx = arr[0], mn = arr[0];
        for(int i=1; i<arr.size(); i++) {
            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);
        }

        if(((mx - mn) % (arr.size() - 1)) != 0) return false;

        int diff = (mx - mn) / (arr.size() - 1);
        if(diff == 0) return true;

        for(int i=0; i<arr.size(); i++) {
            if(arr[i] == mn + i * diff) continue;
            if(((arr[i] - mn) % diff) != 0) return false;
            int idx = (arr[i] - mn) / diff;
            if(arr[idx] == arr[i]) return false;
            swap(arr[idx], arr[i]);
            i--;
        }
        return true;
    }
};
