/*
g와 s를 오름차순으로 정렬하고, 탐색되는 아이가 수용 가능한 쿠키를 만나면 다음 아이를 탐색해줍니다.
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        while(i < g.size()) {
            while(j < s.size() && g[i] > s[j]) j++;
            if(j == s.size()) break;
            i++, j++;
        }

        return i;
    }
};
