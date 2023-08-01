/*
s1[i] == s2[j]라면, 문자를 삭제할 필요는 없습니다.
s1[i] != s2[j]라면, 문자를 삭제하는 경우와 삭제하지 않는 경우로 분기해줍니다.
dp[x][y] = 인덱스 x~y 사이의 처리된 결과를 저장해서 재사용해줍니다.
*/

class Solution {
public:
    int dp[1000][1000] = {0};

    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return minimumDeleteSum(s1, s2, 0, 0);
    }

    int minimumDeleteSum(string& s1, string& s2, int i, int j) {
        if(i == s1.size() || j == s2.size()) {
            if(i == s1.size() && j == s2.size()) return 0;
            int sum = 0;
            if (i == s1.size()) {
                for(int k=j; k<s2.size(); k++) sum += s2[k];
            } else {
                for(int k=i; k<s1.size(); k++) sum += s1[k];
            }
            return sum;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if(s1[i] == s2[j]) {
            return dp[i][j] = minimumDeleteSum(s1, s2, i + 1, j + 1);
        } else {
            return dp[i][j] = min(
                minimumDeleteSum(s1, s2, i + 1, j) + s1[i],
                minimumDeleteSum(s1, s2, i, j + 1) + s2[j] 
            );
        }
    }
};
