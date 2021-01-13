#include <iostream>
#include <vector>
using namespace std;
int ans[6];

void lotto(vector<int>& nums, vector<bool> visited, int c) {
	if (c == 6) {
		for (int i = 0; i < 6; i++) printf("%d ", ans[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < nums.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			ans[c] = nums[i];
			lotto(nums, visited, c + 1);
		}
	}
}

int main()
{
	int n;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		vector<int> nums(n);
		vector<bool> visited(n, false);
		for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
		lotto(nums, visited, 0);
		printf("\n");
	}
}