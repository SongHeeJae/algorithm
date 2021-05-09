#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;

int main() {
	cin >> a >> b;
	while (a.size() != b.size()) {
		if (b.back() == 'A') {
			b.pop_back();
		}
		else {
			b.pop_back();
			reverse(b.begin(), b.end());
		}
	}
	printf("%d", a == b);
}

/*
T와 S의 길이가 같아질 때 까지, T에 가해진 연산을 취소하며 S로 바꿀 수 있는지 확인해주었습니다.
T의 끝문자가 'A'라면, 첫 번째 연산을 취소해줍니다.
T의 끝문자가 'B'라면, 두 번째 연산을 취소해줍니다.
*/