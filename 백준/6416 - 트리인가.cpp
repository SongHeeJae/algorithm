#include <iostream>
#include <set>
using namespace std;
int main() {
	for (int k = 1; ; k++) {
		int a, b, c = 0;
		set<int> s;
		for (; scanf("%d %d", &a, &b) && a && b; c++) {
			if (a == -1 && b == -1) return 0;
			s.insert(a);
			s.insert(b);
		}
		printf("Case %d is %sa tree.\n", k, s.size() == ++c || !s.size() ? "": "not ");
	}
}
