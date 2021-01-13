#include <cstdio>
#include <vector>
using std::vector;

void insertSort(vector<int>& nums) {
	for (int i = 1; i < nums.size(); i++) {

		int k = i - 1;
		int temp = nums[i];
		while (k >= 0 && nums[k] > temp) {
			nums[k+1] = nums[k];
			k--;
		}
		nums[k+1] = temp;
	}
}

int main() {
	int n, a;
	vector<int> nums;
	scanf("%d", &n);
	for (int i = 0; i < n && scanf("%d", &a); i++) nums.push_back(a);

	insertSort(nums);

	for (int n : nums) printf("%d\n", n);
}