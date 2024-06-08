/*
인접한 두 수의 아스키코드 값 차이를 모두 더해주면 됩니다.
*/

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for(int i=1; i<s.size(); i++) {
            score += abs(s[i] - s[i - 1]);
        }
        return score;
    }
};
