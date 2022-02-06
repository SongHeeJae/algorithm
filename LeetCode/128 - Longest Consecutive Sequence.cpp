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
*/