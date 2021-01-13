#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;
int main() {
	vector<int> ns;
	int n;
	scanf("%d", &n);
	for (; n != 0; n/= 10) ns.push_back(n % 10);
	std::sort(ns.begin(), ns.end(), [](const int a, const int b) {return a > b; });
	for (int i : ns) printf("%d", i);
}