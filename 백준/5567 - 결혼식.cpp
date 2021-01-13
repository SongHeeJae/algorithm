#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, a, b, c = 0;
	scanf("%d %d", &n, &m);
	vector<vector<bool>> friends(n + 1, vector<bool>(n + 1, false));
	vector<bool> invited(n + 1, false);
	invited[1] = true;
	while (m-- && scanf("%d %d", &a, &b))
		friends[a][b] = friends[b][a] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && friends[i][j]) {
				invited[j] = true;
				c++;
			}
			else if (friends[i][j]) {
				if (friends[1][i] && !invited[j]) {
					invited[j] = true;
					c++;
				}
				if (friends[1][j] && !invited[i]) {
					invited[i] = true;
					c++;
				}
			}
		}
	}
	printf("%d\n", c);
}
