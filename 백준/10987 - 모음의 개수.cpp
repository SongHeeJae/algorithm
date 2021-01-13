#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int alp['z' + 1] = { 0, };
	char c;
	while ((c = getchar()) != '\n')
		alp[c]++;
	printf("%d", alp['a'] + alp['e'] + alp['i'] + alp['o'] + alp['u']);
}

