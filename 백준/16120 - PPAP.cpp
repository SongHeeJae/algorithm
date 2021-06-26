#include <iostream>
#include <string>
using namespace std;

string str;
char stk[1000003] = { 0 };
int top = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		stk[++top] = str[i];
		if (stk[top] == 'P' && stk[top - 1] == 'A' && stk[top - 2] == 'P' && stk[top - 3] == 'P') {
			top -= 3;
		}
	}
	if (top == 2 && stk[top] == 'P') {
		cout << "PPAP";
	}
	else {
		cout << "NP";
	}
}

/*
순서대로 문자를 스택에 담아주면서 최근 네 개의 문자가 'P', 'A', 'P', 'P' 일 때, 스택의 탑 포인터를 조정시켜줍니다.
마지막에 스택에 담긴 문자가 'P' 하나라면 PPAP 문자열입니다.
*/