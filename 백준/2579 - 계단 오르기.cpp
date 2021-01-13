#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, a;
	scanf("%d", &n);
	vector<int> p(n + 1);
	vector<int> s(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);

	s[1] = p[1];
	s[2] = s[1] + p[2];
	s[3] = max(s[0] + p[2], s[1]) + p[3];
	for (int i = 4; i <= n; i++)
		s[i] = max(s[i - 3] + p[i - 1], s[i - 2]) + p[i];

	printf("%d\n", s[n]);


}