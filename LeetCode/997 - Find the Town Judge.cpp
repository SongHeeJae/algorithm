/*
judge는 아무도 신뢰하지 않고, 다른 사람들은 모두 judge를 신뢰합니다.
이러한 신뢰 관계를 방향 그래프로 본다면,
judge 노드는 다른 노드로 향하는 경로가 없어야하하고, 다른 모든 노드는 judge 노드를 향하는 경로가 있어야합니다.
judge 노드의 (indegree - outdegree == n-1(judge를 제외한 노드의 개수))이 되어야합니다.
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int cnt[1001] = { 0 };

        for(auto& p : trust) {
            cnt[p[0]]--;
            cnt[p[1]]++;
        }

        for(int i=1; i<=n; i++)
            if(cnt[i] == n - 1) return i;

        return -1;
    }
};
