/*
db를 이용한 편집거리 문제였습니다.
dp[i][j] = word1[j - 1]까지의 문자열 -> word2[i - 1]까지의 문자열로 변환하기 위한 최소 연산 횟수를 저장해줍니다.
dp의 0번 인덱스는 공집합을 의미합니다.

word1[j - 1] == word2[i - 1]라면,
별도의 편집 없이 동일한 알파벳을 추가하면 되므로,
dp[i][j] = dp[i - 1][j - 1];

word1[j - 1] != word2[i - 1]라면,
이전 상태에서 삽입(dp[i - 1][j]), 치환(dp[i - 1][j - 1]), 삭제(dp[i][j - 1]) 연산 중 하나를 수행하면 되므로,
dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1;
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[501][501] = {0};
        for(int i=1; i<=word1.size(); i++) {
            dp[0][i] = i;
        }
        for(int i=1; i<=word2.size(); i++) {
            dp[i][0] = i;
        }

        for(int i=1; i<=word2.size(); i++) {
            for(int j=1; j<=word1.size(); j++) {
                if(word1[j - 1] == word2[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + 1;
                }
            }
        }

        return dp[word2.size()][word1.size()];
    }
};
