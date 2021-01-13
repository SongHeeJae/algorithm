#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;


int main() {
	int n, a;
	vector<int> nums;
	scanf("%d", &n);
	for (int i = 0; i < n && scanf("%d", &a); i++) nums.push_back(a);

	std::sort(nums.begin(), nums.end());

	for (int n : nums) printf("%d\n", n);
}