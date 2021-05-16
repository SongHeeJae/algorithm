#include <iostream>
#include <algorithm>
using namespace std;
int a[3][3], sum, t = 0;

void initSum() {
	if (a[0][0] + a[1][1] + a[2][2] == 0 || a[0][2] + a[1][1] + a[2][0] == 0)
		sum = t / 2;
	else {
		sum = max(a[0][0] + a[2][2], a[0][2] + a[2][0]) + a[1][1];
		for (int i = 0; i < 3; i++) {
			int s1 = 0, s2 = 0;
			for (int j = 0; j < 3; j++) s1 += a[i][j], s2 += a[j][i];
			sum = max({ sum, s1, s2 });
		}
	}
}

void fillNumber(bool flag) {
	for (int i = 0; i < 3; i++) {
		int c = 0, idx = -1, s = 0;
		for (int j = 0; j < 3; j++) {
			int val = flag ? a[i][j] : a[j][i];
			if (val == 0) idx = j, c++;
			s += val;
		}
		if (c == 1) (flag ? a[i][idx] : a[idx][i]) = sum - s != 0 ? sum - s : s / 2;
	}
}

void print() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
			t += a[i][j];
		}
	}
	initSum();
	fillNumber(true);
	fillNumber(false);
	print();
}

/*
지워진 수는 3개 이하입니다.
따라서 가로, 세로, 대각선 중 세 개의 칸이 꽉 차있는 마방진의 기준 합을 먼저 구해둔다면,
지워진 수가 한 칸인 행 또는 열의 빈 칸을 채워주기 -> 지워진 수가 한 칸인 열 또는 행의  빈 칸을 채워주는 과정을 통해 원래의 마방진을 구할 수 있습니다.

기준 합을 구하는 과정은 두 가지로 나뉘게 됩니다.
1. 모든 가로, 세로, 대각선에서 지워진 수가 하나씩 나타나는 경우
0 ? ? 
? 0 ? 
? ? 0
또는
? ? 0
? 0 ?
0 ? ? 인 경우,
0이 아닌 칸의 모든 합을 더한 뒤, 2로 나눠주면 대각선의 합인 기준 합을 구할 수 있게 됩니다.

2. 위 1번의 상황이 아닌 경우
지워진 수는 0으로 채워져있기 때문에,
모든 가로, 세로, 대각선의 합을 검사하면서 가장 큰 값이 기준 합이 됩니다.

기준 합을 구해둔 뒤, 행 또는 열 -> 열 또는 행의 순서로 검사하면서 지워진 수가 한 칸인 라인을 채워주면 됩니다.
*/