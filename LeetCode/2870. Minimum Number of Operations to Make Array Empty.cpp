/*
각 수의 개수를 구해줍니다.
개수가 1개인 수가 있다면 빈 배열로 만들 수 없습니다.
개수가 n개라면 n / 3 + (n % 3 != 0 ? 1 : 0)이 n을 없애는 최소 연산 횟수가 됩니다.
n % 3 == 0 이라면, 3개 삭제 연산을 (n / 3)번 수행해주면 됩니다.
n % 3 == 1 이라면, 3개 삭제 연산을 (n / 3 - 1)번, 2개 삭제 연산을 2번(3개 + 나머지 1개) 수행해주면 됩니다. 
n % 3 == 2 이라면, 3개 삭제 연산을 (n / 3)번, 2개 삭제 연산을 1번(나머지 2개) 수행해주면 됩니다.
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt[1000001] = {0};
        for(int num : nums) cnt[num]++;
        
        int res = 0;
        for(int i=1; i<1000001; i++) {
            if(cnt[i] == 1) return -1;
            res += cnt[i] / 3 + (cnt[i] % 3 != 0);
        }
        return res;
    }
};
