#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n, a, b, c, s = 0;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--) {
		cin >> a;
		pq.push(a);
	}
	while (pq.size() != 1) {
		b = pq.top();
		pq.pop();
		c = pq.top();
		pq.pop();
		pq.push(b + c);
		s += b + c;
	}
	cout << s;
}