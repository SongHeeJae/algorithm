#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a, ans = 0, mm = 0;
vector<int> book[2]; // 양수 영역, 음수 영역
void run(vector<int>& arr) {
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i += m)
		ans += -arr[i] * 2;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n && scanf("%d", &a); i++) {
		if (a > 0) book[0].push_back(a = -a);
		else book[1].push_back(a);
		mm = min(a, mm); // 가장 먼 지점
	}
	run(book[0]);
	run(book[1]);
	printf("%d", ans + mm); // 가장 먼 지점은 책을 가져다놓고 종료
}

/*
음수 영역, 양수 영역 각각 가장 멀리 있는 책부터  M권의 책을 가져다두었습니다.
원점으로 돌아올 필요는 없으니, 가장 멀리 있는 책은 가져다 둔 위치에서 종료됩니다.
*/