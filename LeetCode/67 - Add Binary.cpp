/*
2개의 바이너리 문자열을 더하는 문제였습니다.
carry bit를 기억하면서 두 문자열의 끝에서부터 덧셈을 진행하였습니다.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int ai = a.length() - 1, bi = b.length() - 1, c = 0;
        string res = "";
        
        while(ai >= 0 || bi >= 0) {
            int s = c;
            if(ai >= 0) s += a[ai--] - '0';
            if(bi >= 0) s += b[bi--] - '0';
            res.push_back((s % 2) + '0');
            c = s / 2;
        }

        if(c) res.push_back('1');

        reverse(res.begin(), res.end());
        return res;
    }
};
