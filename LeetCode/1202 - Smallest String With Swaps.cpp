/*
인덱스 쌍으로 만들어지는 같은 그룹들을 모아줍니다.
같은 그룹 내에서는 사전 순으로 정렬시켜 줄 수 있습니다.
유니온 파인드를 이용하여 인덱스 번호들을 문자와 함께 같은 그룹으로 묶어줍니다.
문자와 인덱스 번호들을 오름차순 정렬해주고,
이를 이용하여 같은 그룹 내에서는 오름차순을 유지하는 문자열을 만들어줍니다.
*/

class Solution {
public:
    int g[100000] = {0};
    map<int, pair<vector<int>, vector<char>>> group;
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(int i=0; i<s.size(); i++)
            g[i] = i;
        
        for(vector<int>& pair : pairs) {
            int ga = findGroup(pair[0]);
            int gb = findGroup(pair[1]);
            if(ga != gb) g[ga] = gb;
        }
        
        for(int i=0; i<s.size(); i++) {
            auto& grp = group[findGroup(i)];
            grp.first.push_back(i);
            grp.second.push_back(s[i]);
        }
        
        for(auto& it : group) {
            sort(it.second.first.begin(), it.second.first.end());
            sort(it.second.second.begin(), it.second.second.end());
            int sz = it.second.first.size();
            for(int i=0; i<sz; i++)
                s[it.second.first[i]] = it.second.second[i];    
        }
        return s;
    }
    
    int findGroup(int x) {
        if(g[x] == x) return x;
        else return g[x] = findGroup(g[x]);
    }
};