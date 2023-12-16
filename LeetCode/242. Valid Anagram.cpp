/*
s와 t는 소문자 알파벳으로 구성되어있으므로, 26개의 배열로 각 문자의 개수를 구해줍니다. 
동일한 개수를 가진다면 anagram입니다.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        int cnt[26] = {0};
        for(int i=0; i<s.size(); i++) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }

        for(int i=0; i<26; i++) {
            if(cnt[i]) return false;
        }
        return true;
    }
};

/*
follow up - 입력에 유니코드 문자가 있는 경우, s와 t를 정렬해서 동일한 문자열인지 확인하면 됩니다.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

/*
또는, 26개의 배열 대신 map을 이용하여 각 문자의 개수를 구해줘도 됩니다.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> cnt;
        for(int i=0; i<s.size(); i++) {
            cnt[s[i]]++;
            cnt[t[i]]--;
        }
        for(auto& p : cnt) {
            if(p.second) return false;
        }
        return true;
    }
};
