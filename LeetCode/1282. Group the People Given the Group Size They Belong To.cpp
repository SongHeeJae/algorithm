/*
같은 크기의 그룹 사람들을 묶어주고, 주어진 크기가 되면 그루핑해줍니다.
*/

class Solution {
public:
    vector<int> grp[501];
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        for(int i=0; i<groupSizes.size(); i++) {
            int sz = groupSizes[i];
            grp[sz].push_back(i);
            if(grp[sz].size() == sz) {
                res.push_back(grp[sz]);
                grp[sz].clear();
            }
        }

        return res;
    }
};
