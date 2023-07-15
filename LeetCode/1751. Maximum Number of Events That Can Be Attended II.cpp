/*
events를 오름차순으로 정렬하고, 현재 이벤트를 선택 또는 미선택하는 경우를 분기하면서, 다음으로 선택 가능한 이벤트를 탐색해줍니다.
dp를 이용하여 시간을 단축시킬 수 있었습니다.
*/

class Solution {
public:
    
    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<int>> dp(events.size(), vector<int>(k + 1, 0));
        sort(events.begin(), events.end());
        return dfs(events, 0, k, dp);
    }

    int dfs(vector<vector<int>>& events, int idx, int k, vector<vector<int>>& dp) {
        if(k == 0 || idx >= events.size()) return 0;

        if(dp[idx][k]) return dp[idx][k];
    
        int nxt = idx + 1;
        while(nxt<events.size() && events[idx][1] >= events[nxt][0])
            nxt++;

        return dp[idx][k] = max(
            dfs(events, idx + 1, k, dp),
            dfs(events, nxt, k - 1, dp) + events[idx][2]    
        );
    }
};


