/*
각 플레이어들의 패배 횟수를 구해줍니다.
answer[0]은 패배 횟수가 0, answer[1]은 패배 횟수가 1이 됩니다.
*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2, vector<int>());

        unordered_map<int, int> cnt;
        for(auto& m : matches) {
            auto f = cnt.find(m[0]);
            if(f == cnt.end()) {
                cnt[m[0]] = 0;
            }
            cnt[m[1]]++;
        }

        for(auto& c : cnt) {
            if(c.second == 0) {
                res[0].push_back(c.first);
            } else if(c.second == 1) {
                res[1].push_back(c.first);
            }
        }

        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());

        return res;
    }
};
