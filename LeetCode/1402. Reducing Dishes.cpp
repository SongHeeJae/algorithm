/*
satisfaction을 내림차순으로 정렬해주고, 순차적으로 탐색하며 합을 구해줍니다.
각 단계마다 접하는 satisfaction의 누적합 sum을 구하고, 지금까지의 최대 비용을 res라고 하면,
sum > 0일 때에, res += sum을 수행해주면 됩니다.
sum이 양수일 때에만 더해주면 최대 비용을 구할 수 있기 때문입니다.
누적합 sum을 res에 더해주기 때문에, sum이 양수일 때에 수행되는 연산을 정리하면,
s1 + (s1 + s2) + ... + (s1 + s2 + ... + sn)
= (sn * 1) + ... + (s2 + (n - 1)) + (s1 * n)
위와 같은 형태가 될 것입니다. (내림차순 정렬이기 때문에, s1 >= s2 >=  ... >= sn)
*/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int sum = 0, res = 0;
        for(int s : satisfaction) {
            sum += s;
            if(sum > 0) res += sum;
        }
        return res;
    }
};
