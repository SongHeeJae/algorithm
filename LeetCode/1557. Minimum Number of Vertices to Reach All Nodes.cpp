/*
indegree가 0인 노드를 찾아주었습니다.
*/

class Solution {
public:
    bool indegree[100001] = {false};
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        for(vector<int>& edge : edges) {
            indegree[edge[1]] = true;
        }

        vector<int> res;
        for(int i=0; i<n; i++) {
            if(!indegree[i]) res.push_back(i);
        }
        return res;
    }
};
