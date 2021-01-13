#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, a;
	scanf("%d", &n);
	vector<int> num(n);

	for (int i = 0; i < n; i++) scanf("%d", &num[i]);

	if (prev_permutation(num.begin(), num.end())) {
		for (int i : num) printf("%d ", i);
	}
	else printf("-1");
}
