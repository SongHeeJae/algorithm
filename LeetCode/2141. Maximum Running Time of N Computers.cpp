/*
배터리를 내림차순으로 정렬하고, 배터리 시간의 총합을 구해줍니다.
(총합 / 컴퓨터 개수)가 내림차순으로 순회하는 배터리 시간보다 크면, n개의 컴퓨터를 동시에 실행할 수는 없습니다.
총합에서 현재 순회하는 배터리 시간을 차감해주고, (n - 1)개의 컴퓨터를 동시에 실행할 수 있는지 다시 확인해줍니다.
*/

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long s = 0;
        for(int b : batteries) s += b;
        sort(batteries.begin(), batteries.end(), greater<>());
        for(int b : batteries) {
            if(b <= s / n) break;
            s -= b;
            n--;
        }
        return s / n;
    }
};
