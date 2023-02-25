/*
모든 수에 대해 홀수는 짝수로 변환하면서 우선순위 큐에 담아줍니다.
곱하기 연산을 수행한들 deviation은 커지므로, 우선순위 큐에 담긴 값들은 나누기 연산만 수행하면 됩니다.
최솟값을 업데이트하면서, 우선순위 큐의 top(최댓값)을 계속 2로 나누며 최소가 되는 deviation을 구해줍니다.
*/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn = INT_MAX;
        for(int num : nums) {
            int val = num % 2 ? num * 2 : num;
            pq.push(val);
            mn = min(mn, val);
        }

        int res = INT_MAX;
        while(true) {
            int t = pq.top(); pq.pop();
            res = min(res, t - mn);
            if(t % 2) break;
            mn = min(mn, t / 2);
            pq.push(t / 2);
        }
        return res;
    }
};
