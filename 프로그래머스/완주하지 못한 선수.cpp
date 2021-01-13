#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> umap;
    for(int i=0; i<participant.size(); i++) {
        auto find = umap.find(participant[i]);
        if(find != umap.end()) find->second++;
        else umap.insert({participant[i], 1});
    }
    for(int i=0; i<completion.size(); i++) {
        umap[completion[i]]--;
    }
    for(auto iter = umap.begin(); iter != umap.end(); iter++) {
        if(iter->second > 0) {
            answer = iter->first;
            break;
        }
    }
    return answer;
}