#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b) {
	return a.second != b.second ? a.second < b.second : a.first < b.first;
}

int main() {
	vector<pair<int, int>> ns;
	int n, x, y;
	scanf("%d", &n);
	while (n-- && scanf("%d %d", &x, &y)) ns.push_back(make_pair(x, y));
	std::sort(ns.begin(), ns.end(), comp);
	for (pair<int, int> i : ns) printf("%d %d\n", i.first, i.second);
}