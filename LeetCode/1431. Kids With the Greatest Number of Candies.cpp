/*
candies에서 최댓값을 구해준 뒤, ((candies + extraCandies) >= 최댓값)인지 확인해줍니다.
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int mx = candies.front();
        for(int c : candies) mx = max(mx, c);
        for(int c : candies) res.push_back(c + extraCandies >= mx);
        return res;
    }
};
