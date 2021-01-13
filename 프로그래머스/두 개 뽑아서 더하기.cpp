#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void calSum(vector<int>& numbers, int idx, int sum, int cnt, vector<int>& temp) {
    if(cnt == 2) {
        temp.push_back(sum);
        return;   
    } else if(idx == numbers.size()) return;
    
    calSum(numbers, idx+1, sum, cnt, temp);
    calSum(numbers, idx+1, sum+numbers[idx], cnt+1, temp);
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer, temp;
    calSum(numbers, 0, 0, 0, temp);
    sort(temp.begin(), temp.end());
    int prev = -1;
    for(int i=0; i<temp.size(); i++) {
        if(temp[i] != prev) {
            answer.push_back(temp[i]);
            prev = temp[i];
        }
    }
    return answer;
}