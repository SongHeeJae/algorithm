/*
수의 범위가 10억까지 이므로, 우측 30비트만 검사해주면 됩니다.
(a의 비트 | b의 비트) == (c의 비트)면 바꿔줄 필요가 없습니다.
그렇지 않을 때에,
c의 비트가 1이면, (a의 비트 | b의 비트)는 0이고, 두 비트는 (0, 0)이라는 것을 의미하므로, 하나의 비트만 1로 바꿔주면 되고,(+1)
c의 비트가 0이면, (a의 비트 | b의 비트)는 1이고, 두 비트는 (0, 1) 또는 (1, 0) 또는 (1, 1)이라는 것을 의미하므로, 1인 비트만 0으로 바꿔주면 됩니다.(+1 또는 +2)
*/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for(int i=0; i<30; i++) {
            bool aOne = (a >> i) & 1;
            bool bOne = (b >> i) & 1;
            bool cOne = (c >> i) & 1;
            if((aOne | bOne) == cOne) continue;
            cnt += cOne ? 1 : aOne + bOne;
        }
        return cnt;
    }
};
