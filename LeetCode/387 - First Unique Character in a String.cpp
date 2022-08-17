class Solution {
public:
    int v[26] = {0};
    
    int firstUniqChar(string s) {
        for(int i=0; i<s.size(); i++)
            v[s[i] - 'a']++;
        for(int i=0; i<s.size(); i++)
            if(v[s[i] - 'a'] == 1) return i;
        return -1;
    }
};
