/*
비트마스킹을 이용하였습니다.
s의 문자를 탐색하며 문자를 표시해줍니다.
현재 파티션에서 이미 탐색됐던 문자라면, 새로운 파티션을 열어줍니다.
*/

class Solution {
public:
    int partitionString(string s) {
        int flag = 0, cnt = 1;
        for(char c : s) {
            int m = 1 << (c - 'a');
            if(flag & m) {
                cnt++;
                flag = 0;
            }
            flag |= m;
        }
        return cnt;
    }
};
