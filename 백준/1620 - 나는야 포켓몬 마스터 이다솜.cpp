#include <iostream>
#include <map>
int main()
{
	int n, m;
	char s[21];
	std::map<std::string, int> data1;
	std::map<int, std::string> data2;
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		data1.insert(std::make_pair(s, i));
		data2.insert(std::make_pair(i, s));

	}
	while (m--)
	{
		scanf("%s", s);
		'1' <= s[0] && s[0] <= '9' ? printf("%s\n", data2.find(atoi(s))->second.c_str()) : printf("%d\n", data1.find(s)->second);
	}
}
