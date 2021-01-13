#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, vector<string>> umap;
    for(int i=0; i<clothes.size(); i++) {
        auto find = umap.find(clothes[i][1]);
        if(find != umap.end()) {
            find->second.push_back(clothes[i][0]);
        } else {
            vector<string> temp;
            temp.push_back(clothes[i][0]);
            umap.insert({clothes[i][1], temp});
        }
    }
    for(auto iter = umap.begin(); iter != umap.end(); iter++) {
        answer *= iter->second.size() + 1;
    }
    return answer - 1;
}