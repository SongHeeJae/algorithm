/*
가장 오른쪽 숫자부터 탐색하며, 홀수가 처음 나오는 지점까지의 substring이 가장 큰 홀수가 됩니다.
*/

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size() - 1; i>=0; i--) {
            if((num[i] - '0') % 2) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
