/*
center node는 모든 edge에 나와야하므로, 임의의 두개의 노드만 검사해줘도 됩니다.
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ?
            edges[0][0] : edges[0][1];
    }
};
