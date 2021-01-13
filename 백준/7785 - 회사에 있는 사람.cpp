#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
	int n;
	set<string> log;
	pair<set<string>::iterator, bool> pr;
	char a[6];
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", a);
		if (!(pr=log.insert(a)).second) log.erase(a);
		scanf("%s", a);
	}

	for (set<string>::reverse_iterator it=log.rbegin(); it!=log.rend(); it++)
		printf("%s\n", it->c_str());
}
