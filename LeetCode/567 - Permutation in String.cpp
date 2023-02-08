/*
s1의 알파벳 개수를 초기화하고, s1의 크기만큼 개수를 나타내는 윈도우 사이즈를 슬라이딩해주며 풀 수 있었습니다.
*/

class Solution {
public:
    int cnt[26] = {0};
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) {
            return false;
        }

        for(char c : s1) {
            cnt[c - 'a']++;
        }

        for(int i=0; i<s1.size(); i++) {
            cnt[s2[i] - 'a']--;
        }

        for(int i=s1.size(); i<s2.size(); i++) {
            if(chk()) return true;
            cnt[s2[i - s1.size()] - 'a']++;
            cnt[s2[i] - 'a']--;
        }

        return chk();
    }

    bool chk() {
        for(int i=0; i<26; i++)
            if(cnt[i] != 0) return false;
        return true;
    }
};
