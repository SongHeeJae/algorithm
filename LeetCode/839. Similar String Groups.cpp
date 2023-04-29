/*
두 문자열에서 다른 문자가 2개 이하라면, 두 문자열은 Similar String입니다.

DFS를 이용한 풀이입니다.
Similar String으로 그래프를 만들고, 그룹의 개수를 구해주었습니다.
*/

class Solution {
public:
    vector<int> graph[300];
    bool visit[300] = {false};
    int numSimilarGroups(vector<string>& strs) {
        for(int i=0; i<strs.size(); i++) {
            for(int j=i+1; j<strs.size(); j++) {
                if(isSmilar(strs[i], strs[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
    
        int res = 0;
        for(int i=0; i<strs.size(); i++) {
            if(visit[i]) continue;
            dfs(i);
            res++;
        }

        return res;
    }

    bool isSmilar(string& x, string& y) {
        int c = 0;
        for(int i=0; i<x.size(); i++)
            if(x[i] != y[i]) c++;
        return c <= 2;
    }

    void dfs(int idx) {
        if(visit[idx]) return;
        visit[idx] = true;
        for(int nxt : graph[idx]) {
            dfs(nxt);
        }
    }
};


/*
Union Find를 이용한 풀이입니다.
새로운 그룹이 만들어지는지 확인해줍니다.
*/

class Solution {
public:
    int p[300];
    int numSimilarGroups(vector<string>& strs) {
        for(int i=0; i<strs.size(); i++) p[i] = i;

        int res = strs.size();
        for(int i=0; i<strs.size(); i++) {
            for(int j=i+1; j<strs.size(); j++) {
                if(isSmilar(strs[i], strs[j])) {
                    int pi = findParent(i);
                    int pj = findParent(j);
                    if(pi != pj) {
                        p[pi] = p[pj];
                        res--;
                    }
                }
            }
        }
    
        return res;
    }

    bool isSmilar(string& x, string& y) {
        int c = 0;
        for(int i=0; i<x.size(); i++)
            if(x[i] != y[i]) c++;
        return c <= 2;
    }

    int findParent(int x) {
        if(p[x] == x) return x;
        return p[x] = findParent(p[x]);
    }
};
