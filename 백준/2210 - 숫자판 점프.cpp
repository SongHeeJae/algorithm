#include <iostream>
#include <set>
using namespace std;
set<string> st;
char map[5][5];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
string temp = "";
void dfs(int x, int y, int d) {
	if (d == 6) {
		st.insert(temp);
		return;
	}
	temp.push_back(map[x][y]);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
		dfs(nx, ny, d + 1);
	}
	temp.pop_back();
}

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) scanf(" %c", &map[i][j]);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) dfs(i, j, 0);
	printf("%d", st.size());
}