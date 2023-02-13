/*
x까지의 홀수의 개수는 (x + 1) / 2로 구할 수 있습니다.
high까지의 홀수 개수 - (low - 1)까지의 홀수 개수를 구해줍니다.
*/

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};
