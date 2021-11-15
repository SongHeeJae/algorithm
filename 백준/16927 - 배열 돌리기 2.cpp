#include <iostream>
#define MAX 300
using namespace std;

int n, m, r, arr[MAX][MAX];

void rotate() {
	int d = 0;
	while (d < (n+1) / 2 && d < (m+1) / 2) {
		int rr = r % (2 * n + 2 * m - 4 - 8 * d);
		while (rr--) {
			int temp = arr[d][d];
			for (int i = d; i < m - 1 - d; i++)
				arr[d][i] = arr[d][i + 1];
			for (int i = d; i < n - 1 - d; i++)
				arr[i][m - 1 - d] = arr[i + 1][m - 1 - d];
			for (int i = m - 1 - d; i > d; i--)
				arr[n - 1 - d][i] = arr[n - 1 - d][i - 1];
			for (int i = n - 1 - d; i > d; i--)
				arr[i][d] = arr[i - 1][d];
			arr[d + 1][d] = temp;
		}
		d++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	rotate();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

/*
각 둘레마다 꼭 r번을 모두 다 회전해야할 필요는 없습니다.
둘레의 깊이가 d일 때,
(n - 1 - d * 2) * 2 + (m - 1 - d * 2) * 2)번 회전할 때마다
원래의 위치로 돌아오게 됩니다.
따라서 각 둘레마다 r을 위 값으로 나눈 나머지 횟수만큼만 회전해주면 됩니다. 
*/