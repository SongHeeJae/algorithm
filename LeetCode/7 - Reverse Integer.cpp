class Solution {
public:
    const int MAX = 214748364;
    int reverse(int x) {
        if(x < -8463847412 || x > 7463847412) return 0;
        int result = 0;
        while(x) {
            int val = x % 10;
            if(result >= MAX && val >= 7 || result > MAX) return 0;
            if(result <= -MAX && val >= 8 || result < -MAX) return 0;
            result = result * 10 + val;
            x /= 10;
        }
        return result;
    }
};

/*
64비트 정수와 오버플로우가 허용되지 않는 제약이 걸려있었습니다.
역순으로 뒤집어가면서 새로운 수를 추가하게 될 때 오버플로우가 발생하는지 확인해주었습니다.
*/