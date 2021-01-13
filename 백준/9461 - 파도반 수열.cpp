#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, a;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a);
		vector<long long int> len(a < 5 ? 5 : a);
		len[0] = len[1] = len[2] = 1;
		len[3] = len[4] = 2;
		for (int i = 5; i < a; i++) len[i] = len[i - 1] + len[i - 5];
		printf("%lld\n", len[a-1]);
	}
}