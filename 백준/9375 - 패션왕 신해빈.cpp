#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	map<string, int> data;
	char s[21], ss[21];
	int a, b, sum;
	scanf("%d", &a);
	while (a--)
	{
		data.clear();
		sum = 1;
		scanf("%d", &b);
		while (b--)
		{
			scanf("%s", s);
			scanf("%s", ss);
			if (data.find(ss) != data.end()) (data.find(ss))->second++;
			else data.insert(make_pair(ss, 1));
		}
		for (map<string, int>::iterator it=data.begin(); it != data.end(); it++) sum *= it->second + 1;
		printf("%d\n", --sum);
	}
}
