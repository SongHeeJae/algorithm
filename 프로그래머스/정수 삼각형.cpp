#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size();
    for(int i=1; i<height; i++) {
        triangle[i][0] += triangle[i-1][0];
        int size = triangle[i].size();
        for(int j=1; j < size - 1; j++) {
            triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
        }
        triangle[i][size-1] += triangle[i-1][size-2];
    }
    for(int i=0; i<triangle[height-1].size(); i++) {
        answer = max(answer, triangle[height-1][i]);
    }
    return answer;
}