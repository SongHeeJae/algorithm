/*
반복문을 한 번 순회하며 가장 큰 값과 두번째로 큰 값을 구해줍니다.
가장 큰 값을 새롭게 찾을 때, 그 때의 값은 두번째로 큰 값이 됩니다.
배열의 첫번째 값이 가장 큰 값인 경우가 있으므로, 가장 큰 값을 못 찾더라도 두번째로 큰 값은 찾아줍니다.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1 = 0, mx2 = 0;
        for(int num : nums) {
            if(mx1 <= num) {
                mx2 = mx1;
                mx1 = num;
            } else if(mx2 <= num) {
                mx2 = num;
            }
        }
        return (mx1 - 1) * (mx2 - 1);
    }
};
