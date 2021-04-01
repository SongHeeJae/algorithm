#include <iostream>
#include <map>
using namespace std;

map<int, int> set;
int n, m, a, b, c;

int findParent(int x) {
	auto f = set.find(x);
	if (f != set.end()) return f->second = findParent(f->second);
	else return x;
}

int main() {
	scanf("%d %d", &n, &m);
	while (m-- && scanf("%d %d %d", &a, &b, &c))
		if (a == 0) {
			int ab = findParent(b);
			int ac = findParent(c);
			if(ab != ac) set.insert({ ab, ac });
		}
		else {
			printf("%s\n", findParent(b) == findParent(c) ? "YES" : "NO");
		}
}

/*
각 집합의 조상을 구해주고, 조상이 다르다면 그 조상끼리 같은 집합으로 묶어주었습니다.
*/