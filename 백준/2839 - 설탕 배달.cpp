#include <iostream>
using namespace std;
int main()
{
	int kg, count = 0;
	cin >> kg;
	for (;kg>0;count++) kg = (kg % 3 == 0 && kg % 5 != 0) ? kg - 3 : kg - 5;
	printf("%d", (kg!=0)?-1:count);
}