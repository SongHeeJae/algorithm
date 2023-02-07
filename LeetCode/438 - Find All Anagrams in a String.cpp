/*
슬라이딩 윈도우를 이용하여 풀 수 있었습니다.
먼저 p의 모든 알파벳 개수를 초기화해줍니다.
초기화된 개수에서, s를 탐색하면서 지금 방문하는 알파벳 개수를 p의 길이만큼 유지하면서 증감해줍니다.
s[i]를 탐색할 때 증감된 알파벳 개수가 0이라면, (i - p 길이) 인덱스에서 시작된 substring은 anagram이 될 수 있음을 의미합니다.  
*/

class Solution {
public:
    int cnt[26] = {0};
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};

        for(char c : p) 
            cnt[c - 'a']++;

        for(int i=0; i<p.size(); i++)
            cnt[s[i] - 'a']--;

        vector<int> res;

        for(int i=p.size(); i<s.size(); i++) {
            if(chk()) res.push_back(i - p.size());
            cnt[s[i - p.size()] - 'a']++;
            cnt[s[i] - 'a']--;
        }

        if(chk())
            res.push_back(s.size() - p.size());

        return res;
    }

    bool chk() {
        for(int i=0; i<26; i++)
            if(cnt[i] != 0) return false;
        return true;
    }
};
