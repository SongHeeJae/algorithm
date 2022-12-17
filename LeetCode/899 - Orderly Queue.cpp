/*
k = 1 이면, 가장 앞에 있는 문자가 뒤로 갈 수만 있습니다. O(n^2)의 시간으로 모든 경우를 확인해줍니다.

k > 1 이면, 문자의 대소를 확인할 수 있습니다. 즉, 모든 문자를 재정렬할 수 있습니다. 오름차순으로 정렬해줍니다.
*/

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1) {
            sort(s.begin(), s.end());
            return s;
        }

        string ans = s;
        for(int i=1; i<s.size(); i++)
            ans = min(ans, s.substr(i) + s.substr(0, i));
        return ans;
    }
};
