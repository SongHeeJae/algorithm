/*
브루트포스로 푼 뒤, dp[i][seatCount]에 메모이제이션을 적용해주었습니다.
*/

class Solution {
public:
    int dp[100001][3];

    int numberOfWays(string corridor) {
        memset(dp, -1, sizeof(dp));
        return numberOfWays(corridor, 0, 0);
    }

    int numberOfWays(string& corridor, int idx, int seat) {
        if(idx == corridor.size()) {
            return seat == 2;
        }

        int& cnt = dp[idx][seat];
        if(cnt != -1) return cnt;
        cnt = 0;

        seat += corridor[idx] == 'S';
        if (seat >= 3) {
            return cnt = 0;
        }

        if (seat == 2) {
            return cnt = (numberOfWays(corridor, idx + 1, 0) + numberOfWays(corridor, idx + 1, seat)) % 1000000007;
        } 
        
        return cnt = numberOfWays(corridor, idx + 1, seat) % 1000000007;
    }
};
