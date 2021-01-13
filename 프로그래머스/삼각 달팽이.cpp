#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> arr(n);
    int val = 1, x = 0, y = 0;
    for(int i=0; i<n; i++) arr[i].resize(i+1);
    while(n > 0) {
        for(int i=0; i<n; i++) arr[x++][y] = val++;
        n--; x--; y++;
        for(int i=0; i<n; i++) arr[x][y++] = val++;
        n--; y--; y--; x--;
        for(int i=0; i<n; i++) arr[x--][y--] = val++;
        n--; x++; x++; y++;
    }
    for(int i=0; i<arr.size(); i++)
        for(int j=0; j<arr[i].size(); j++)
          answer.push_back(arr[i][j]);
    return answer;
}