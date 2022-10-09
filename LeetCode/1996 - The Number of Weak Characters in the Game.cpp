/*
attack 내림차순, defence 오름차순으로 정렬해줍니다.
순차적으로 탐색하면서 defence의 최댓값을 업데이트해줍니다.
현재 탐색하고 있는 defence가 최댓값보다 작다면, weak character입니다.
*/

bool comp(vector<int>& a, vector<int>& b) {
    return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
}

class Solution {
public:    
    int numberOfWeakCharacters(vector<vector<int>>& props) {
        sort(props.begin(), props.end(), comp);
        int mx = props[0][1];
        int cnt = 0;
        for(auto& prop : props) {
            if(prop[1] < mx) cnt++;
            mx = max(mx, prop[1]);
        }
        return cnt++;
    }
};
