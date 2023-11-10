/*
길이 n의 부분 문자열이 연속되는 문자로 이루어져있다면, 1+2+...+n개 만큼 만들어질 수 있습니다.
*/

class Solution {
public:
    int countHomogenous(string s) {
        int cnt = 1, res = 1;
        for(int i=1; i<s.size(); i++) {
            if(s[i - 1] == s[i]) {
                cnt++;
            } else {
                cnt = 1;
            }
            res = (res + cnt) % 1000000007;
        }
        return res;
    }
};

class Solution {
public:
    int countHomogenous(string s) {
        s.push_back(' ');
        int cnt = 1, res = 0;
        for(int i=1; i<s.size(); i++) {
            if(s[i - 1] == s[i]) {
                cnt++;
            } else {
                res = (res + sumOfOneToN(cnt)) % 1000000007;
                cnt = 1;
            }
        }
        return res;
    }

private:
    long long sumOfOneToN(int n) {
        return ((long long) n * (n + 1) / 2);
    }
};
