#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix(int a, int b) {
	vector<vector<int>> m(a, vector<int>(b));
	int x;
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b && scanf("%d", &x); j++)
			m[i][j] = x;
	return m;
}

vector<vector<int>> dot(vector<vector<int>>& a, vector<vector<int>>& b) {
	vector<vector<int>> ans(a.size(), vector<int>(b[0].size(), 0));

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			int s = 0;
			for (int k = 0; k < b.size(); k++)
				s += a[i][k] * b[k][j];
			ans[i][j] = s;
		}
	}
	return ans;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> m1 = matrix(n, m);
	scanf("%d %d", &n, &m);
	vector<vector<int>> m2 = matrix(n, m);
	vector<vector<int>> ans = dot(m1, m2);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[0].size(); j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
}