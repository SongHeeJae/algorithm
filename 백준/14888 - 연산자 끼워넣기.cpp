#include <iostream>
#include <vector>
using namespace std;

int maxVal = -987654321;
int minVal = 987654321;

void calMaxMin(vector<int>& nums, int o[4], int val, int c) {
	if (c == nums.size()) {
		maxVal = val > maxVal ? val : maxVal;
		minVal = val < minVal ? val : minVal;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (o[i] == 0) continue;
		o[i]--;
		switch (i) {
		case 0:
			calMaxMin(nums, o, val + nums[c], c + 1);
			break;
		case 1:
			calMaxMin(nums, o, val - nums[c], c + 1);
			break;
		case 2:
			calMaxMin(nums, o, val * nums[c], c + 1);
			break;
		default:
			calMaxMin(nums, o, val / nums[c], c + 1);
		}
		o[i]++;
	}
}

int main() {
	int n;
	int o[4];
	scanf("%d", &n);
	vector<int> nums(n);
	for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
	for (int i = 0; i < 4; i++) scanf("%d", &o[i]);

	calMaxMin(nums, o, nums[0], 1);

	printf("%d\n%d\n", maxVal, minVal);

}