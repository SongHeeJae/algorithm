/*
수를 오른쪽부터 검사하면서,
좌측 수가 우측 수보다 작다면 뺄셈 연산을,
좌측 수가 우측 수보다 크거나 같다면 덧셈 연산을 수행해주었습니다.
*/

class Solution {
public:
    int romanToInt(string s) {
        int res = convert(s[s.size() - 1]);
        for(int i = s.size() - 2; i >= 0; i--) {
            int val = convert(s[i]);
            int nVal = convert(s[i + 1]);
            if(val < nVal) res -= val;
            else res += val;
        }
        return res;
    }
private:
    int convert(char roman) {
        if(roman == 'I') return 1;
        else if(roman == 'V') return 5;
        else if(roman == 'X') return 10;
        else if(roman == 'L') return 50;
        else if(roman == 'C') return 100;
        else if(roman == 'D') return 500;
        else return 1000;
    }
};
