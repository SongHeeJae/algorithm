/*
먼저 words[0]의 각 문자 개수를 구해줍니다.
이어서, 남은 words를 순회하며 각 문자 개수를 구해주고, words[0]에 나타났던 문자 개수 만큼만 기억해줍니다.
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int cnt[26] = {0};
        for(char c : words[0]) cnt[c - 'a']++;

        for(int i=1; i<words.size(); i++) {
            int temp[26] = {0};
            for(char c : words[i]) {
                temp[c - 'a']++;
            }
            for(int j=0; j<26; j++) {
                cnt[j] = min(cnt[j], temp[j]);
            }
        }

        vector<string> res;
        for(int i=0; i<26; i++) {
            for(int j=0; j<cnt[i]; j++) {
                res.push_back(string(1, i + 'a'));
            }
        }
        return res;
    }
};
