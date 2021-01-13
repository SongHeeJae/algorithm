#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cards;
int n, m;

int bsearch(int x) {
	int l = 0;
	int r = cards.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (x > cards[mid]) {
			l = mid + 1;
		}
		else if (x < cards[mid]) {
			r = mid - 1;
		}
		else {
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> m;
		cards.push_back(m);
	}

	sort(cards.begin(), cards.end());

	cin >> n;
	while (n--) {
		cin >> m;
		cout << bsearch(m) << " ";
	}
}