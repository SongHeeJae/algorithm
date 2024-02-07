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



/*
빈도 수를 이용하여 정렬 없이 풀 수 있었습니다.
각 문자의 빈도 수를 구해주고, 각 빈도 수에 대응하는 문자들을 기억해줍니다. 
빈도 수 내림차순으로 순회하며 정렬된 문자열을 만들어줍니다.
*/

class Solution {
public:
    int cnt['z' + 1] = { 0 };
    string frequencySort(string s) {
        for(int i=0; i<s.size(); i++) cnt[s[i]]++;

        vector<vector<char>> arr(s.size() + 1);
        for(int i='A'; i<='Z'; i++) arr[cnt[i]].push_back(i);
        for(int i='a'; i<='z'; i++) arr[cnt[i]].push_back(i);
        for(int i='0'; i<='9'; i++) arr[cnt[i]].push_back(i);
        
        string res = "";
        for(int i=s.size(); i>0; i--)
            for(char c : arr[i])
                res += string(i, c);
        return res;
    }
};
