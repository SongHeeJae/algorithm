#include <iostream>
#include <vector>
using namespace std;
vector<int> arr, res;
int n, a;

int lowerBound(int target) {
	int s = 0, e = res.size() - 1;
	while (s < e) {
		int mid = (s + e) / 2;
		if (res[mid] >= target) e = mid;
		else s = mid + 1;
	}
	return e;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n && scanf("%d", &a); i++) arr.push_back(a);
	res.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (arr[i] <= res[res.size() - 1])
			res[lowerBound(arr[i])] = arr[i];
		else res.push_back(arr[i]);
	}
	printf("%d", res.size());
}