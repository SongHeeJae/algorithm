#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int n, nge[1000000], a;
stack<pair<int, int>> stk;

int main() {
	memset(nge, -1, sizeof(nge));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		while (!stk.empty() && a > stk.top().first) {
			nge[stk.top().second] = a;
			stk.pop();
		}
		stk.push({ a, i });
	}
	for (int i = 0; i < n; i++) printf("%d ", nge[i]);
}

/*
스택의 탑이 지금 입력받은 수보다 작다면, 스택의 탑에 입력된 수의 오큰수는 지금 입력 받은 수입니다.
*/