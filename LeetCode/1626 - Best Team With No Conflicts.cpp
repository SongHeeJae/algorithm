/*
dp를 이용하여 풀 수 있었습니다.
주어진 플레이어를, 나이 오름차순 > 점수 오름차순으로 정렬해줍니다.
위 순서로 플레이어를 방문해주면, 적어도 i번보다 낮은 인덱스의 플레이어들은 충돌되지 않고, 나이가 동일하더라도 더 큰 점수의 플레이어와 엮일 수 있습니다.
dp[i] = i번 플레이어까지 있을 때의 최대 점수를 저장해줄 것입니다.
i번보다 낮은 인덱스 j의 플레이어들을 방문하면서,
i보다 j의 점수보다 크거나 같을 경우(충돌하지 않는 플레이어 j가 더 큰 점수를 가지는 경우),
dp[i] = max(dp[i], dp[j] + player.score) (j와의 팀 여부에 따라 더 큰 점수를 취할 수 있는 상황) 으로 업데이트해줍니다.
*/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        for(int i=0; i<scores.size(); i++) {
            players.push_back({ages[i], scores[i]});
        }

        sort(players.begin(), players.end(), [](auto& a, auto& b) -> bool {
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        int ans = 0;
        for(int i=0; i<players.size(); i++) {
            dp[i] = players[i].second;
            for(int j=i-1; j>=0; j--) {
                if(players[i].second >= players[j].second) {
                    dp[i] = max(dp[i], dp[j] + players[i].second);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }

private:
    vector<pair<int, int>> players;
    int dp[1000] = {0}; // i번째 까지의 최대 점수

};
