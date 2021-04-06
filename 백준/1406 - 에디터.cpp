#include <iostream>
#include <list>
using namespace std;
int m;
char ch;
list<char> li;
list<char>::iterator it;
int main() {
	while ((m = getchar()) != '\n') li.push_back(m);
	it = li.end();
	scanf("%d", &m);
	while (m--) {
		scanf(" %c", &ch);
		if (ch == 'L') {
			if (it != li.begin()) it--;
		}
		else if (ch == 'D') {
			if(it != li.end()) it++;
		}
		else if (ch == 'B') {
			if (it == li.begin()) continue;
			it--;
			it = li.erase(it);
		}
		else {
			scanf(" %c", &ch);
			it = li.insert(it, ch);
			it++;
		}
	}
	for (it = li.begin(); it != li.end(); it++) printf("%c", *it);
}

/*
중간 데이터 삽입 및 삭제 작업을 빠르게 하기 위해 리스트를 이용하여 풀었습니다.
*/