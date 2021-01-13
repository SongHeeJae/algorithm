#include <iostream>
#include <vector>
using namespace std;

void printNums(vector<int>& nums, int n, int m, int c) {
	if (c == m) {
		for (int i : nums) printf("%d ", i);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		nums[c] = i;
		printNums(nums, n, m, c + 1);
	}

	
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> nums(m, 0);
	printNums(nums, n, m, 0);
}