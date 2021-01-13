#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void qsort(vector<int>& cards, int l, int r) {
	if (l >= r) return;
	int pivot = cards[(l + r) / 2];
	int i = l - 1;
	int j = r + 1;
	while (true) {
		while (cards[++i] < pivot);
		while (cards[--j] > pivot);
		if (i >= j) break;
		int temp = cards[i];
		cards[i] = cards[j];
		cards[j] = temp;
	}
	qsort(cards, l, i-1);
	qsort(cards, j + 1, r);
}

int upperBound(vector<int>& cards, int num) {
	int s = 0, e = cards.size() - 1;
	while (e > s) {
		int mid = (s + e) / 2;
		if (cards[mid] > num) e = mid;
		else s = mid + 1;
	}
	return e == cards.size()-1 && cards[e] <= num ? e + 1 : e;
}

int lowerBound(vector<int>& cards, int num) {
	int s = 0, e = cards.size() - 1;
	while (e > s) {
		int mid = (s + e) / 2;
		if (cards[mid] >= num) e = mid;
		else s = mid + 1;
	}
	return e == 0 && cards[e] < num ? e + 1 : e;
}

int main() {
	int n, m, a;
	scanf("%d", &n);
	vector<int> cards(n);
	for (int i = 0; i < n; i++) scanf("%d", &cards[i]);
	qsort(cards, 0, n - 1);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &a);
		printf("%d ", (upper_bound(cards.begin(), cards.end(), a) - cards.begin()) - (lower_bound(cards.begin(), cards.end(), a) - cards.begin()));
	}
}