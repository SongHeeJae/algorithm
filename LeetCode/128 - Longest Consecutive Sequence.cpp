class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int mx = 0;
        for(int num : st) {
            int prv = num - 1;
            int nxt = num + 1;
            while(st.find(prv) != st.end()) st.erase(prv--);
            while(st.find(nxt) != st.end()) st.erase(nxt++);
            mx = max(mx, nxt - prv - 1);
        }
        return mx;
    }
};

/*
모든 숫자들을 unordered_set에 담아줍니다.
unordered_set을 순회하면서, 각 숫자마다 좌우를 검사하며 길이를 구해줍니다.
아직 검사하지 않은 숫자에 대해 위 과정을 반복하며 최대 길이를 구해줍니다.

---

다음과 같은 방법으로도 풀이할 수 있었습니다.
이미 검사된 범위는 넘어가도록 하고, 기존의 unordered_set은 건드리지 않는 것입니다.
검사한 모든 요소들을 제거하는 작업이 사라져서 더 빨라지지 않을까 싶었습니다.
물론, 검사된 범위에 속하는지 확인하는 작업이 필요해서 데이터에 따른 차이가 있을 듯 합니다

class Solution {
private:
    vector<pair<int, int>> checkedRange;
public:
    bool isChecked(int val) {
        for(pair<int, int> &p : checkedRange)
            if(p.first < val && val < p.second) return true;
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int mx = 0;
        for(int num : st) {
            if(isChecked(num)) continue;
            int prv = num - 1;
            int nxt = num + 1;
            while(st.find(prv--) != st.end());
            while(st.find(nxt++) != st.end());
            checkedRange.push_back({prv, nxt});
            mx = max(mx, nxt - prv - 3);
        }
        return mx;
    }
};
*/