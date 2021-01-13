#include <iostream>
using namespace std;

int main() {
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);
	printf("%d\n", (int)(((double)v-a)/(a-b)+0.9999) + 1);

}