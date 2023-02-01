/*
두 문자열 a와 b가 있을 때, a + b != b + a 라면 gcd가 없습니다.(a + b = n*gcd + m*gcd = b + a)
그렇지 않다면, 두 문자열의 최대공약수 길이의 문자열이 gcd가 될 수 있습니다.
*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};
