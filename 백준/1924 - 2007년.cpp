#include <iostream>
using namespace std;
int main()
{
	int m, d;
	const char *s[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	const char *a = "003344555667";
	cin >> m >> d;
	puts(s[((31*(--m)) - (a[m] - '0') + d) % 7]);
}