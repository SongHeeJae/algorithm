/*
동일한 문자 경로를 그래프로 만들어서 풀 수 있었습니다.
같은 문자들을 동일한 그룹으로 표시해줍니다.
*/

class Solution {
public:
    vector<char> graph[26];
    int visit[26] = {0};

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i=0;i<s1.size(); i++) {
            graph[s1[i] - 'a'].push_back(s2[i]);
            graph[s2[i] - 'a'].push_back(s1[i]);
        }

        string result = "";
        for(char c : baseStr) {
            dfs(c, c);
            result.push_back(findMinCharacterInEqGroup(c));
        }
        return result;
    }

    void dfs(char c, int v) {
        if(visit[c - 'a']) return;
        visit[c - 'a'] = v;
        for(char n : graph[c - 'a']) dfs(n, v);
    }

    char findMinCharacterInEqGroup(char c) {
        for(int j=0; j<26; j++)
            if(visit[j] == visit[c - 'a']) return j + 'a';
        return -1;
    }
};


/*
다음과 같이 유니온 파인드를 이용하여 풀 수도 있었습니다.
큰 문자에서 작은 문자로 이동될 수 있도록 합니다.
*/

class Solution {
public:
    int p[26] = {0};

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        memset(p, -1, sizeof(p));

        for(int i=0;i<s1.size(); i++) {
            int p1 = find(s1[i] - 'a');
            int p2 = find(s2[i] - 'a');
            if(p1 != p2)
                p[max(p1, p2)] = min(p1, p2);
        }

        string result = "";
        for(char c : baseStr)
            result.push_back(find(c - 'a') + 'a');
        return result;
    }

    int find(int x) {
        if(p[x] == -1) return x;
        return p[x] = find(p[x]);
    }
};
