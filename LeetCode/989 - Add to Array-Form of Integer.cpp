/*
k를 10씩 나눠가며 10으로 나눈 나머지를 num의 끝에다가 계속 더해줍니다.
다음 수로 넘어가는 올림 수를 기억하고, num의 자릿수를 모두 사용했으면, 남은 k를 모두 올림 수로 취급하여 남은 덧셈 연산을 수행해줍니다.
*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int c = 0;
        for(int i=num.size() - 1; i>=0; i--) {
            int s = num[i] + k % 10 + c;
            num[i] = s % 10;
            c = s / 10;
            k /= 10;
        }
        c += k;
        
        while(c) {
            num.insert(num.begin(), c % 10);
            c /= 10;
        }
        
        return num;
    }
};
