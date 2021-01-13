#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    int i, j, k;
    for(int r=0; r<commands.size(); r++){
        i=commands[r][0], j=commands[r][1], k=commands[r][2];
        temp.clear();
        for(int idx=i-1; idx<j; idx++)
            temp.push_back(array[idx]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k-1]);
    }
    return answer;
}