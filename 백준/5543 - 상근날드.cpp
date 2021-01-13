#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a, s1 = 2000,s2=2000;
	for (int i = 0; i < 3 && scanf("%d", &a); i++) s1=min(s1, a);
	for (int i = 0; i < 2 && scanf("%d", &a); i++) s2=min(s2, a);
	printf("%d", s1+s2-50);
}