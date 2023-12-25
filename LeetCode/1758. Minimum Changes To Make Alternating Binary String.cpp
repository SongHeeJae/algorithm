/*
첫번째 문자가 0인 경우와 1인 경우를 가정해서, 두 경우에 대한 연산 횟수 중 더 작은 값을 구해줍니다. 
*/

class Solution {
public:
    int minOperations(string s) {
        int c1 = 0, c2 = 0;
        for(int i=0; i<s.size(); i++) {
            if(i % 2) {
                if(s[i] == '1') c1++;
                else c2++;
            } else {
                if(s[i] == '0') c1++;
                else c2++;
            }
        }
        return min(c1, c2);
    }
};
