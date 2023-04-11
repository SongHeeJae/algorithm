/*
새로운 문자열을 선언하고, 연산이 수행된 문자열을 만들어줍니다.
*/

class Solution {
public:
    string removeStars(string s) {
        string res = "";
        for(char c : s) {
            if(c == '*') {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};

/*
투포인터를 이용하여, 한 포인터는 문자열을 순차적으로 탐색하고, 나머지 포인터는 연산이 수행된 결과의 포인터를 기억해줍니다.
*/

class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '*') {
                j--;
            } else {
                s[j++] = s[i];
            }
        }
        return s.substr(0, j);
    }
};
