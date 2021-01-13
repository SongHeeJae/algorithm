#include <iostream>
using namespace std;
int n, m;
char a, b;
char color[7] = "wyrogb"; // 0흰,1노,2빨,3오,4초,5파
int cube[6][3][3]; // 0위,1밑,2앞,3뒤,4왼,5오

void copy(int a[][3], int b[][3]) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) a[i][j] = b[i][j];
}

void change(int idx, char d) {
	int temp[3][3];
	if (d == '+') {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) temp[j][2 - i] = cube[idx][i][j];
	}
	else {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) temp[2 - j][i] = cube[idx][i][j];
	}
	copy(cube[idx], temp);
}

void rot(int p[], int t[], int tt[][6]) {
	for (int i = 0; i < 3; i++) {
		cube[t[i]][tt[i][0]][tt[i][1]] = cube[t[i + 1]][tt[i + 1][0]][tt[i + 1][1]];
		cube[t[i]][tt[i][2]][tt[i][3]] = cube[t[i + 1]][tt[i + 1][2]][tt[i + 1][3]];
		cube[t[i]][tt[i][4]][tt[i][5]] = cube[t[i + 1]][tt[i + 1][4]][tt[i + 1][5]];
	}
	cube[t[3]][tt[3][0]][tt[3][1]] = p[0];
	cube[t[3]][tt[3][2]][tt[3][3]] = p[1];
	cube[t[3]][tt[3][4]][tt[3][5]] = p[2];
}

void rotate(char r, char d) {
	if (r == 'U') {
		change(0, d);
		int p[] = { cube[2][0][0], cube[2][0][1], cube[2][0][2] };
		if (d == '+') {
			int t[] = { 2, 5, 3, 4 };
			int tt[][6] = { {0,0,0,1,0,2}, {2,0,1,0,0,0}, {2,2,2,1,2,0}, {0,2,1,2,2,2} };
			rot(p, t, tt);
		}
		else {
			int t[] = { 2, 4, 3, 5 };
			int tt[][6] = { {0,0,0,1,0,2}, {0,2,1,2,2,2}, {2,2,2,1,2,0}, {2,0,1,0,0,0} };
			rot(p, t, tt);
		}
	}
	else if (r == 'D') {
		change(1, d);
		int p[] = { cube[2][2][0], cube[2][2][1], cube[2][2][2] };
		if (d == '+') {
			int t[] = { 2, 4, 3, 5 };
			int tt[][6] = { {2,0,2,1,2,2}, {0,0,1,0,2,0}, {0,2,0,1,0,0}, {2,2,1,2,0,2} };
			rot(p, t, tt);
		}
		else {
			int t[] = { 2, 5, 3, 4 };
			int tt[][6] = { {2,0,2,1,2,2}, {2,2,1,2,0,2}, {0,2,0,1,0,0}, {0,0,1,0,2,0}, };
			rot(p, t, tt);
		}
	}
	else if (r == 'F') {
		change(2, d);
		int p[] = { cube[0][2][0], cube[0][2][1], cube[0][2][2] };
		int tt[][6] = { {2,0,2,1,2,2}, {2,0,2,1,2,2}, {0,2,0,1,0,0}, {2,0,2,1,2,2} };
		if (d == '+') {
			int t[] = { 0, 4, 1, 5 };
			rot(p, t, tt);
		}
		else {
			int t[] = { 0, 5, 1, 4 };
			rot(p, t, tt);
		}
	}
	else if (r == 'B') {
		change(3, d);
		int p[] = { cube[0][0][2], cube[0][0][1], cube[0][0][0] };
		int tt[][6] = { {0,2,0,1,0,0}, {0,2,0,1,0,0}, {2,0,2,1,2,2}, {0,2,0,1,0,0} };
		if (d == '+') {
			int t[] = { 0, 5, 1, 4 };
			rot(p, t, tt);
		}
		else {
			int t[] = { 0, 4, 1, 5 };
			rot(p, t, tt);
		}
	}
	else if (r == 'L') {
		change(4, d);
		int p[] = { cube[0][0][0], cube[0][1][0], cube[0][2][0] };
		int tt[][6] = { {0,0,1,0,2,0}, {0,0,1,0,2,0}, {0,0,1,0,2,0}, {0,0,1,0,2,0} };
		if (d == '+') {
			int t[] = { 0, 3, 1, 2 };
			rot(p, t, tt);		
		}
		else {
			int t[] = { 0, 2, 1, 3 };
			rot(p, t, tt);
		}
	}
	else {
		change(5, d);
		int p[] = { cube[0][2][2], cube[0][1][2], cube[0][0][2] };
		int tt[][6] = { {2,2,1,2,0,2}, {2,2,1,2,0,2}, {2,2,1,2,0,2}, {2,2,1,2,0,2} };
		if (d == '+') {
			int t[] = { 0, 2, 1, 3 };
			rot(p, t, tt);
		}
		else {
			int t[] = { 0, 3, 1, 2 };
			rot(p, t, tt);
		}
	}
}

void print() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) cout << color[cube[0][i][j]];
		cout << "\n";
	}
}

void initCube() {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++) cube[i][j][k] = i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	while (n--) {
		initCube();
		cin >> m;
		while (m--) {
			cin >> a >> b;
			rotate(a, b);
		}
		print();
	}
}