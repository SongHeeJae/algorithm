/*
연속된 세 개의 숫자가 같다면, 해당 수에 대해 최댓값을 업데이트해줍니다.
*/

class Solution {
public:
    string largestGoodInteger(string num) {
        int mx = -1;
        for(int i=2; i<num.size(); i++) {
            if(num[i] == num[i - 1] && num[i] == num[i - 2]) mx = max(mx, num[i] - '0');
        }

        if (mx == -1) return "";
        else if(mx == 0) return "000";
        return to_string(mx * 100 + mx * 10 + mx);
    }
};
