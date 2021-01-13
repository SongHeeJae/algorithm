#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		string s1, s2;
		cin >> s1 >> s2;
		printf("Distances: ");
		for (int i = 0; i < s1.length(); i++)
			printf("%d ", s2[i] - s1[i] < 0 ? 26 + (s2[i] - s1[i]) : s2[i] - s1[i]);
		printf("\n");
	}
}

