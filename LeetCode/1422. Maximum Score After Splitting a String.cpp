/*
1의 개수를 구해두고, s를 다시 순회하며 각 지점에서의 0과 1의 개수를 구하여 점수를 계산해줍니다. 
*/

class Solution {
public:
    int maxScore(string s) {
        int oc = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '1') oc++;
        }
        
        int res = 0, zc = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '0') zc++;
            else oc--;
            res = max(res, zc + oc);
        }
        return res;
    }
};
