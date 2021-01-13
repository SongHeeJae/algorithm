#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;
int main() {
	int n, a = 0, b = 0, c, count = 0, x, min = 4001, max = -4001, maxbin = -1;
	scanf("%d", &n);
	vector<int> nums(8001, 0);
	for (int i = 0; i < n && scanf("%d", &x); i++) {
		a += x;
		max = x > max ? x : max;
		min = x < min ? x : min;
		nums[x + 4000]++;
		maxbin = nums[x + 4000] > maxbin ? nums[x + 4000] : maxbin;
	}

	vector<int> bin;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == maxbin) bin.push_back(i - 4000);
		while (b == 0 && nums[i] != 0) {
			if (count++ == n / 2) b = i - 4000;
			nums[i]--;
		}
	}

	std::sort(bin.begin(), bin.end());
	c = bin.size() == 1 ? bin[0] : bin[1];
	printf("%d\n%d\n%d\n%d\n", a < 0 ? (int)(((double)a/n)-0.5) : (int)(((double)a / n) + 0.5), b, c, max - min);
}