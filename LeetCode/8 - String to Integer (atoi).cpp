class Solution {
public:
    int MAX[2] = {-2147483648, 2147483647};
    
    int myAtoi(string s) {
        bool positive = true;
        int idx = 0;
        while(idx < s.size() && s[idx] == ' ') idx++;
        if(idx >= s.size() || s[idx] != '-' && s[idx] != '+' && (s[idx] < '0' || s[idx] > '9')) return 0;
        if(s[idx] == '-') positive = false;
        if(s[idx] == '-' || s[idx] == '+') {
            if(++idx >= s.size() || s[idx] < '0' || s[idx] > '9') return 0;
        }
        
        int result = 0;
        while(idx < s.size() && '0' <= s[idx] && s[idx] <= '9') {
            int val = s[idx] - '0';
            if(isOverflow(result, val)) return MAX[positive];
            result = result * 10 + (positive ? val : -val);
            idx++;
        }
        return result;
    }
    
    bool isOverflow(int cur, int val) {
        return cur >= 214748364 && val > 7 || cur > 214748364
            || cur <= -214748364 && val > 8 || cur < -214748364;
    }
};

/*
1. 공백을 다 넘겨줍니다.
2. 부호 또는 숫자가 아니라면, return 0
3. '-'라면, 기억해줍니다.
4. 부호이고 다음 칸이 숫자가 아니라면, return 0
5. 연속되는 숫자를 int로 바꾸어줍니다. 도중에 오버플로우가 발생하려고 하면, return 0 


자료형에 대한 별다른 제약이 걸려있지 않아서, 다른 자료형으로 해결할 수도 있었습니다.

class Solution {
public:
    int myAtoi(string s) {
        bool positive = true;
        int idx = 0;
        while(idx < s.size() && s[idx] == ' ') idx++;
        if(idx >= s.size() || s[idx] != '-' && s[idx] != '+' && (s[idx] < '0' || s[idx] > '9')) return 0;
        if(s[idx] == '-') positive = false;
        if(s[idx] == '-' || s[idx] == '+') {
            if(++idx >= s.size() || s[idx] < '0' || s[idx] > '9') return 0;
        }
        
        long long result = 0;
        while(idx < s.size() && '0' <= s[idx] && s[idx] <= '9') {
            int val = s[idx] - '0';
            result = result * 10 + (positive ? val : -val);
            if(positive) {
                if(result > INT_MAX) return INT_MAX;
            } else {
                if(result < INT_MIN) return INT_MIN;
            }
            idx++;
        }
        return result;
    }
};
*/