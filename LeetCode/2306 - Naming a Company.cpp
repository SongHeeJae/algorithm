/*
첫 글자와 나머지 문자열을 분리하여, 첫 글자가 동일한 idea를 동일한 set에 담아줍니다.
한 set에 있는 idea가 다른 set에 있는 idea에 포함되지 않는다면, 유효한 네이밍이 됩니다.
모든 두 set간의 조합을 검사하면서, 각 경우에 서로 포함되는 idea 개수를 구해줍니다.
이 개수는 선택된 두 set 간에 이름을 만들 수 없는 idea 개수를 의미합니다.
해당 개수를 제외한, 두 set의 모든 idea로 만들 수 있는 경우의 수를 구해줍니다.
*/

class Solution {
public:
    unordered_set<string> ideaSet[26];

    long long distinctNames(vector<string>& ideas) {
        for(string& idea : ideas) {
            ideaSet[idea[0] - 'a'].insert(idea.substr(1));
        }
        
        long long res = 0;
        for(int i=0; i<25; i++) {
            for(int j=i+1; j<26; j++) {
                int cnt = 0;
                for(auto& idea : ideaSet[i]) {
                    if(ideaSet[j].find(idea) != ideaSet[j].end()) {
                        cnt++;
                    }
                }
                res += (ideaSet[i].size() - cnt) * (ideaSet[j].size() - cnt);
            }
        }
        return res * 2;
    }
};
