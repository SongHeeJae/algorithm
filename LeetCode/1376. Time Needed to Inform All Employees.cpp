/*
하위 노드에서 상위 노드로 올라가며 informTime[i]에 i번 employee에게 전달될 때 까지 걸리는 시간을 저장해줍니다.
가장 크게 걸리는 시간을 구해줍니다.
*/

class Solution {
public:

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        for(int i=0; i<manager.size(); i++) {
            res = max(res, dfs(i, manager, informTime));
        }
        return res;
    }

    int dfs(int e, vector<int>& manager, vector<int>& informTime) {
        if(manager[e] == -1) return informTime[e];
        informTime[e] += dfs(manager[e], manager, informTime);
        manager[e] = -1;
        return informTime[e];
    }
};

