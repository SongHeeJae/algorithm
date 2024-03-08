class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int cnt[101] = {0}, mx = 0, res = 0;
        for(int num : nums) mx = max(mx, ++cnt[num]);
        for(int i=1; i<101; i++)
            if(cnt[i] == mx) res += mx;
        return res;
    }
};
