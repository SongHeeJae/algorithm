/*
쿠키와 k는 최대 8이므로, dfs로 풀 수 있었습니다.
*/

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> s(k, 0);
        return dfs(cookies, s, k, 0);
    }

    int dfs(vector<int>& c, vector<int>& s, int k, int idx) {
        if(idx == c.size()) {
            int mx = INT_MIN;
            for(int ss : s) mx = max(mx, ss);
            return mx;
        }

        int mn = INT_MAX;
        for(int i=0; i<k; i++) {
            s[i] += c[idx];
            mn = min(mn, dfs(c, s, k, idx + 1));
            s[i] -= c[idx];
        }

        return mn;
    }
};
