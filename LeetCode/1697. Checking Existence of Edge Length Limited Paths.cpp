/*
edgeList를 distance 오름차순으로, queries를 limit 오름차순으로 정렬해줍니다.
기존 queries의 순서대로 answer를 반환해야하므로, 정렬하기 전에 인덱스 위치도 기억해줍니다.
각 query를 순차적으로 탐색하면서, 현재 query의 limit 미만인 모든 edgeList를 같은 집합으로 묶어줍니다.
현재 query의 limit 미만인 모든 edge를 같은 집합으로 묶어주었을 때, 질의하는 두 노드가 같은 집합에 있는지 확인해줍니다.
*/

class Solution {
public:
    int p[100000];

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for(int i=0; i<n; i++) p[i] = i;
        sort(edgeList.begin(), edgeList.end(), [](auto& a, auto& b){
            return a[2] < b[2];
        });

        for(int i=0; i<queries.size(); i++) queries[i].push_back(i);

        sort(queries.begin(), queries.end(), [](auto& a, auto& b){
            return a[2] < b[2];
        });


        vector<bool> result(queries.size(), false);
        int i = 0;
        for(auto& query : queries) {
            while(i < edgeList.size() && edgeList[i][2] < query[2]) {
               int p1 = findParent(edgeList[i][0]);
               int p2 = findParent(edgeList[i][1]);
               if(p1 != p2) p[p1] = p2;
               i++;
            }

            result[query[3]] = findParent(query[0]) == findParent(query[1]);
        }

        return result;
    }

    int findParent(int x) {
        if(p[x] == x) return x;
        return p[x] = findParent(p[x]);
    }
};
