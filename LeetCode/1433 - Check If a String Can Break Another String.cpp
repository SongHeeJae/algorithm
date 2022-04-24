/*
알파벳의 개수만큼 배열을 선언하고, 각 문자열마다 문자의 개수를 구해줍니다.
배열을 순회하면서, 어떤 문자열의 문자가 사전순으로 먼저 앞서게 되는지 기억해줍니다.
다음 문자들을 검사하면서, 앞섰던 문자열의 문자가 앞서지 않게 된다면, false를 반환해주면 됩니다.
*/

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int chk1[26] = {0}, chk2[26] = {0};
        for(int i=0; i<s1.size(); i++) {
            chk1[s1[i] - 'a']++;
            chk2[s2[i] - 'a']++;
        }
        
        int v1 = 0, v2 = 0, flag = 0;
        for(int i=0; i<26; i++) {
            v1 += chk1[i];
            v2 += chk2[i];
            if(flag == 0) {
                if(v1 > v2) flag = 1;
                else if(v1 < v2) flag = 2;
            }
            if(flag == 1 && v1 < v2 || flag == 2 && v1 > v2) return false;
        }
        return true;
    }
};