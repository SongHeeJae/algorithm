#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;

int main()
{
	int n, m, index[1000], j;
	vector<string> str;
	string temp;
	scanf("%d", &n);
	while (n--)
	{
		str.clear();
		scanf("%d", &m);
		str.resize(m);
		for (int i = 0; i < m && std::cin >> str[i]; i++);
		for (int i = 0; i < m && std::cin >> temp; i++)
		{
			for (j = 0; j < m; j++) if (str[j] == temp) break;
			index[i] = j;
		}
		str.clear();
		str.resize(m);
		for (int i = 0; i < m && std::cin >> temp; i++) str[index[i]] = temp;
		for (int i = 0; i < m; i++) printf("%s ", str[i].c_str());
		printf("\n");
	}
}