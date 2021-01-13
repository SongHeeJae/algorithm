#include <iostream>
#include <vector>
using namespace std;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, 1, -1, 0 };

int dfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int x, int y) {
	int c = 0;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < map[0].size()
			&& yy < map[0].size() && map[xx][yy]
			&& !visited[xx][yy]) {
			visited[xx][yy] = true;
			c += dfs(map, visited, xx, yy);
		}
	}
	return ++c;
}

void msort(vector<int>& ans, int l, int r, vector<int>& buf) {

	if (l >= r) return;

	int mid = (l + r) / 2;
	int i = l;
	int j = mid + 1;
	int k = l;
	
	msort(ans, l, mid, buf);
	msort(ans, mid + 1, r, buf);
	
	while (i <= mid && j <= r) {
		if (ans[i] > ans[j]) buf[k++] = ans[j++];
		else buf[k++] = ans[i++];
	}

	while (i <= mid) buf[k++] = ans[i++];
	while (j <= r) buf[k++] = ans[j++];

	for (int i = l; i <= r; i++) ans[i] = buf[i];
}

int main() {
 
	int n;
	scanf("%d", &n);
	vector<vector<int>> map(n, vector<int>(n));
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	vector<int> ans;
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = getchar() - '0';
		}
		getchar();
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] && !visited[i][j]) {
				visited[i][j] = true;
				ans.push_back(dfs(map, visited, i, j));
			}
		}
	}
	vector<int> buf(ans.size());
	msort(ans, 0, ans.size() - 1, buf);
	printf("%d\n", ans.size());
	for (int i : ans) printf("%d\n", i);
}
