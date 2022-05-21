/*
dp를 이용하여 풀 수 있었습니다.
dp[i] = i원을 만들 수 있는 동전의 최소 개수를 저장해줍니다.
기존에 있는 동전은 1로 표시해주고, 금액을 점차 올려나가며 동전의 최소 개수를 업데이트해주면 됩니다.
*/

class Solution {
public:
    int dp[10001];
    int coinChange(vector<int>& coins, int amount) {
        for(int i=1;i<=amount; i++) dp[i] = 10001;
        for(int coin : coins)
            if(coin <= 10000) dp[coin] = 1;
        for(int i=1;i<=amount; i++) {
            for(int coin : coins) {
                if(i - coin < 1) continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == 10001 ? -1 : dp[amount];
    }
};