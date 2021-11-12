#include <iostream>
#define MAX 2000
using namespace std;

int n;
char s[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	
	int l = 0, r = n - 1, c = 0;
	while (l <= r) {
		if (s[l] < s[r]) cout << s[l++];
		else if (s[l] > s[r]) cout << s[r--];
		else {
			int tl = l, tr = r;
			while (tl < tr && s[tl] == s[tr]) tl++, tr--;
			if (s[tl] < s[tr]) cout << s[l++];
			else cout << s[r--];
		}
		if (++c % 80 == 0) cout << "\n";
	}
}

/*
투 포인터를 이용하였습니다.
첫 인덱스와 마지막 인덱스를 기억하고,
두 문자가 다르다면, 더 앞선 문자를 바로 T에 포함시켜줍니다.
두 문자가 같다면, 지금의 인덱스 지점부터 간격을 좁혀주면서, 가장 처음으로 다른 문자가 나올 때 더 앞선 문자를 가지고 있는 방향을 T에 포함시켜줍니다.
*/