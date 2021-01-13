#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> nums(n + 1, 0);

	for (int i = 2; i <= n; i++) {
		nums[i] = nums[i-1] + 1;
		if (i % 2 == 0)
			nums[i] = min(nums[i], nums[i / 2] + 1);
		if (i % 3 == 0)
			nums[i] = min(nums[i], nums[i / 3] + 1);
	}
	printf("%d\n", nums[n]);

}