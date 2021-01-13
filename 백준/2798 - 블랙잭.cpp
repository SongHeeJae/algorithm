#include <cstdio>
#include <vector>
using std::vector;

int printSum(vector<int>& cards, int m, int sum, int c, int index, int max) {
	if (c == 3) return sum;
	
	if (index >= cards.size()) return -1;

	for (int i = index; i < cards.size(); i++) {
		int result = printSum(cards, m, sum + cards[i], c + 1, i + 1, max);
		max = result <= m && result > max ? result : max;
	}

	return max;
}

int main() {
	int n, m, a;
	vector<int> cards;

	scanf("%d %d", &n, &m);
	while (n-- && scanf("%d", &a)) cards.push_back(a);

	printf("%d\n", printSum(cards, m, 0, 0, 0, 0));
}