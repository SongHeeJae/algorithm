/*
cost의 총합이 gas의 총합보다 크다면 순회할 수 없습니다.
이 외의 경우라면, 고유한 시작 지점이 있을 것입니다.
0번에서 출발을 가정하고, 현재 지점에서의 잔여 gas를 구해줍니다.
잔여 gas가 음수라면, 0번~현재 지점에서는 출발하더라도 순회할 수 없음을 의미합니다.
0번을 지났을 때 양의 gas를 가지고 있었지만, 결국 현재 지점에 도달했을 때 음의 gas에 도달하기 때문입니다.
(현재 지점+1)번에서 다시 출발한다고 가정합니다.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gs = 0, cs = 0;
        int idx = 0, cur = 0;
        for(int i=0;i<gas.size(); i++) {
            gs += gas[i];
            cs += cost[i];
            cur += gas[i] - cost[i];
            if(cur < 0) idx = i + 1, cur = 0;
        }
        return gs < cs ? -1 : idx;
    }
};
