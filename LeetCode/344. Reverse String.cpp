/*
xor 연산을 이용하여 두 수를 스왑하였습니다.
두 수 a와 b가 있을 때,
a = a^b
b = a^b^b = a
a = a^b^a = b
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0; i<s.size()/2; i++) {
            s[i] ^= s[s.size() - i - 1];
            s[s.size() - i - 1] ^= s[i];
            s[i] ^= s[s.size() - i - 1];
        }
    }
};
