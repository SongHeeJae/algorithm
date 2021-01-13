#include <string>
#include <vector>
#include <cstring>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int chk[26];
    memset(chk, -1, sizeof(chk));
    for(int i=1; i<skill.size(); i++) {
        chk[skill[i]-'A'] = skill[i-1]-'A';
    }
    
    for(int i=0; i<skill_trees.size(); i++) {
        bool trees[26] = {false};
        for(int j=0; j<skill_trees[i].size(); j++) {
            int tree = skill_trees[i][j] - 'A';
            if(chk[tree] != -1) {
                if(!trees[chk[tree]]) {
                    answer++;
                    break;
                }
            }
            trees[tree] = true;
        }
    }
    
    return skill_trees.size() - answer;
}