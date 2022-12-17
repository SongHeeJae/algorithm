/*
빈도 수를 구하고, 이를 이용하여 정렬을 할 수 있었습니다. 
*/

class Solution {
public:
    int cnt['z' + 1] = { 0 };
    string frequencySort(string s) {
        for(int i=0; i<s.size(); i++) {
            cnt[s[i]]++;
        }

        sort(s.begin(), s.end(), [this](const char& a, const char& b) -> bool { 
            if(this->cnt[a] == this->cnt[b]) return a > b;
            return this->cnt[a] > this->cnt[b];
});
        return s;
    }
};
