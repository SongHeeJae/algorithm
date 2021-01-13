#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& numbers, int idx, int sum, int target) {
    if(idx == numbers.size()) {
        if(sum == target) return 1;
        return 0;
    }
    return dfs(numbers, idx + 1, sum + numbers[idx], target) + dfs(numbers, idx + 1, sum - numbers[idx], target);
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, 0, 0, target);
}