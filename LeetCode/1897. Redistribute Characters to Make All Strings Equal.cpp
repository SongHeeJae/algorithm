/*
words의 모든 문자의 개수를 구해주고, 각 문자가 words의 길이로 나누어 떨어지는지 확인해줍니다.
*/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnt[26] = {0};
        for(string& w : words) {
            for(char c : w) {
                cnt[c - 'a']++;
            }
        }

        for(int i=0; i<26; i++) {
            if(cnt[i] % words.size() != 0) {
                return false;
            }
        }
        return true;
    }
};
