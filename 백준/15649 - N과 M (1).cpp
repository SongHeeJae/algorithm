#include <cstdio>
#include <vector>
using std::vector;

void NM(int n, int m, int c, bool *visited, vector<int>& nums) {
	
	if (c == m) {
		for (int i : nums) printf("%d ", i);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		nums[c] = i;
		NM(n, m, c + 1, visited, nums);
		visited[i] = false;
	}

}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	bool visited[9] = { false, };
	vector<int> nums(m);
	NM(n, m, 0, visited, nums);
}