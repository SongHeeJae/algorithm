/*
Type 3은 Alice와 Bob이 모두 순회할 수 있으므로, 간선들을 type 내림차순으로 정렬해줍니다.
정렬된 간선을 탐색하면서 연결된 노드들을 같은 그룹으로 묶어줍니다.
이미 같은 그룹이었다면, 해당 간선은 제거해도 됩니다.
모든 연산이 끝나고, Alice와 Bob에 대해서 모든 노드가 하나의 그룹으로 묶였는지 확인해줍니다.
*/

class Solution {
public:
    int pa[100001];
    int pb[100001];
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        for(int i=1; i<=n; i++) pa[i] = pb[i] = i;
        
        sort(edges.begin(), edges.end());

        int res = 0, ac = n, bc = n;
        for(int i = edges.size() - 1; i >= 0; i--) {
            auto& edge = edges[i];
            int type = edge[0], u = edge[1], v = edge[2];
            if(type == 1) {
                int pau = find(u, pa);
                int pav = find(v, pa);    
                if(pau != pav) pa[pau] = pa[pav], ac--;
                else res++;
            } else if(type == 2) {
                int pbu = find(u, pb);
                int pbv = find(v, pb);
                if(pbu != pbv) pb[pbu] = pb[pbv], bc--;  
                else res++;
            } else {
                int pau = find(u, pa);
                int pav = find(v, pa);  
                if(pau != pav) pa[pau] = pa[pav], ac--; 
                int pbu = find(u, pb);
                int pbv = find(v, pb);
                if(pbu != pbv) pb[pbu] = pb[pbv], bc--;  
                if(pau == pav && pbu == pbv) res++;
            }
        }
        
        return ac == 1 && bc == 1 ? res : -1;
    }

    int find(int x, int p[]) {
        return p[x] == x ? x : p[x] = find(p[x], p);
    }
};
