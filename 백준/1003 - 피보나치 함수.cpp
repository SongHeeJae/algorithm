#include <iostream>
using namespace std;

int main()
{
	int data[41][2] = { {1,0} };
	int num;
	int n;
	for (int i = 1; i < 41; i++)
	{
		data[i][0] = data[i - 1][1];
		data[i][1] = data[i][0] + data[i - 1][0];
	}
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		printf("%d %d\n", data[n][0], data[n][1]);
	}
}