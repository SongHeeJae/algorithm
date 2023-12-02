/*
chars의 각 문자 개수를 구해주고, 각 word를 chars에 있는 문자들로 만들 수 있는지 확인합니다.
*/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26] = {0};
        for(char c : chars) {
            cnt[c - 'a']++;
        }
        
        int res = 0;
        int tcnt[26];
        for(string& word : words) {
            for(int i=0; i<26; i++) tcnt[i] = cnt[i];
            bool good = true;
            for(char c : word) {
                if(--tcnt[c - 'a'] < 0) {
                    good = false;
                    break;
                }
            }
            if(good) res += word.size();
        }
        return res;
    }
};
