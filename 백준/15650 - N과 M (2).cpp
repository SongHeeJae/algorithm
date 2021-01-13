#include <iostream>
#include <vector>
using namespace std;

bool visit[9] = { false, };

void printNums(vector<int>& nums, int n, int m, int index, int c) {
	if (c == m) {
		for (int i : nums) printf("%d ", i);
		printf("\n");
		return;
	}

	for (int i = index; i <= n; i++) {
		if (!visit[i]) {
			nums[c] = i;
			visit[i] = true;
			printNums(nums, n, m, i + 1, c + 1);
			visit[i] = false;
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> nums(m, 0);

	printNums(nums, n, m, 1, 0);
}