/*
위상정렬을 이용하여 풀었습니다.
indegree가 0인 노드부터 탐색해나가면서, 현재까지 탐색된 컬러의 최대 개수를 저장해줍니다.
위상정렬을 통해 모든 노드를 방문할 수 없었으면, 노드 간에 사이클이 있었음을 의미합니다.
*/

class Solution {
public:    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for(int i=0;i<n; i++)
            if(indegree[i] == 0) q.push(i);

        int ans = -1, v = 0;
        vector<vector<int>> cnt(n, vector<int>(26, 0));
        while(!q.empty()) {
            int x = q.front(); q.pop();

            ans = max(ans, ++cnt[x][colors[x] - 'a']);

            for(int nxt : graph[x]) {
                for(int i=0; i<26; i++)
                    cnt[nxt][i] = max(cnt[nxt][i], cnt[x][i]);

                if(--indegree[nxt] == 0)
                    q.push(nxt);
            }
            v++;
        }

        return v == n ? ans : -1;
    }
};
