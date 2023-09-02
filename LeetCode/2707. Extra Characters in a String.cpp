/*
s의 substring이 dictionary에 있는지 검사해줍니다.
dictionary에 있다면 해당 지점까지 extra character가 없음을 의미하므로 다음 지점부터 재검사해주고,
extra character가 있는 상황에 더 최적화된 결과를 얻을 수 있으므로 dictionary에 없는 경우도 판별해줍니다.
각 인덱스에 대한 연산 결과는 저장하고 재사용해줍니다.
*/

class Solution {
public:
    int dp[50];
    unordered_set<string> dict;
    
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp, -1, sizeof(dp));
        for(auto& w : dictionary) dict.insert(w);
        return minExtraChar(s, 0);
    }

    int minExtraChar(string& s, int idx) {
        if(idx >= s.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        dp[idx] = minExtraChar(s, idx + 1) + 1;
        for(int i=1; i + idx <= s.size(); i++) {
            if(dict.find(s.substr(idx, i)) != dict.end()) {
                dp[idx] = min(dp[idx], minExtraChar(s, idx + i));
            }
        }
        return dp[idx];
    }
};
