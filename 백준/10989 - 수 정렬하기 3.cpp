#include <cstdio>
#include <vector>
using std::vector;
int main() {
	int n, a;
	scanf("%d", &n);
	vector<int> nums(10000, 0);
	for (int i = 0; i < n && scanf("%d", &a); i++) nums[a - 1]++;

	for (int i = 0; i < nums.size(); i++)
		for (; nums[i] != 0;nums[i]--) printf("%d\n", i + 1);
}