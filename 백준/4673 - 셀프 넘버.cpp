#include <iostream>
using namespace std;
int main()
{
	int i=0, c[10036] = { 0, };
	while(i++ < 9999) c[i + i % 10 + i / 10 % 10 + i / 100 % 10 + i / 1000]++;
	for (i = 0; i++ < 9999; ) if (!c[i]) printf("%d\n", i);
}