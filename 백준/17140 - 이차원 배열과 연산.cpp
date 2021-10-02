#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 100

int r, c, k, mxrc = 3, mxcc = 3, t = 0;
int arr[MAX][MAX], cc[MAX], rc[MAX], cnt[101];
vector<pair<int, int>> temp;

bool compAscSecondAscFirst(pair<int, int>& a, pair<int, int>& b) {
	if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}

void init() {
	memset(cnt, 0, sizeof(cnt));
	temp.clear();
}

void makeSortedStateByElemCnt() {
	for (int i = 1; i < 101 && temp.size() < 50; i++) {
		if (cnt[i]) temp.push_back({ i, cnt[i] });
	}
	sort(temp.begin(), temp.end(), compAscSecondAscFirst);
}

void paddingZeroForRow() {
	for (int i = 0; i < mxrc; i++)
		for (int j = rc[i]; j < mxcc; j++)
			arr[i][j] = 0;
}

int sortRowAndReturnRowCnt(int row) {
	init();
	for (int i = 0; i < mxcc; i++) {
		cnt[arr[row][i]]++;
	}
	makeSortedStateByElemCnt();
	for (int i = 0; i < temp.size(); i++) {
		arr[row][i * 2] = temp[i].first;
		arr[row][i * 2 + 1] = temp[i].second;
	}
	return temp.size() * 2;
}

void sortRowsAndUpdateMaxColCnt() {
	int nmxcc = 0;
	for (int i = 0; i < mxrc; i++) {
		rc[i] = sortRowAndReturnRowCnt(i);
		nmxcc = max(nmxcc, rc[i]);
	}
	mxcc = nmxcc;
	paddingZeroForRow();
}

void paddingZeroForCol() {
	for (int i = 0; i < mxcc; i++)
		for (int j = cc[i]; j < mxrc; j++)
			arr[j][i] = 0;
}

int sortColAndReturnColCnt(int col) {
	init();
	for (int i = 0; i < mxrc; i++) {
		cnt[arr[i][col]]++;
	}
	makeSortedStateByElemCnt();
	for (int i = 0; i < temp.size(); i++) {
		arr[i * 2][col] = temp[i].first;
		arr[i * 2 + 1][col] = temp[i].second;
	}
	return temp.size() * 2;
}

void sortColsAndUpdateMaxRowCnt() {
	int nmxrc = 0;
	for (int i = 0; i < mxcc; i++) {
		cc[i] = sortColAndReturnColCnt(i);
		nmxrc = max(nmxrc, cc[i]);
	}
	mxrc = nmxrc;
	paddingZeroForCol();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	while (arr[r - 1][c - 1] != k && t <= 100) {
		if (mxrc >= mxcc) sortRowsAndUpdateMaxColCnt();
		else sortColsAndUpdateMaxRowCnt();
		t++;
	}

	cout << (t <= 100 ? t : -1);
}

/*
행과 열의 최대 길이를 기억해주면서, 연산을 수행해주었습니다.
*/