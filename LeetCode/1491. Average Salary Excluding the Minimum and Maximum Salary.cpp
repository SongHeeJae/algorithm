/*
salary를 순회하면서, 총합, 최솟값, 최댓값을 구해줍니다.
이를 이용하여 평균을 계산해줍니다.
*/

class Solution {
public:
    double average(vector<int>& salary) {
        int mn = salary.front(), mx = salary.front();
        int sum = 0;
        for(int s : salary) {
            sum += s;
            mn = min(mn, s);
            mx = max(mx, s);
        }
        return (sum - mn - mx) / (salary.size() - 2.0);
    }
};
