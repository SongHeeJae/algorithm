#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> f(n+1);
    f[0] = 0;
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i <= n; i++) f[i] = (f[i - 1] + f[i - 2]) % 15746;
	printf("%d\n", f[n]);
}