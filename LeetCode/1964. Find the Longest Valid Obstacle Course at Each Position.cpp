/*
탐색된 장애물들을 오름차순으로 저장할 수 있는 배열을 선언해줍니다.
장애물들을 순차적으로 탐색하면서, 위 선언한 배열의 upper bound 지점을 찾아줍니다.
찾은 지점을 이용하여 각 장애물을 탐색할 때의 가장 긴 길이를 구할 수 있습니다.
해당 지점에는 지금 탐색한 장애물을 저장해주고, 선언한 배열의 오름차순이 유지되게 합니다.
*/

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> res, arr;
        for(int o : obstacles) {
            int l = 0, r = arr.size();
            while(l < r) {
                int m = (l + r) / 2;
                if(arr[m] <= o) l = m + 1;
                else r = m;
            }
            if(arr.size() <= l) arr.push_back(o);
            else arr[l] = o;
            res.push_back(l + 1);
        }
        return res;
    }
};
