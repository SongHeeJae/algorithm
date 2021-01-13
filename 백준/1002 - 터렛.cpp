#include <iostream>
#include <math.h>
using namespace std;

int location(int x1, int y1, int r1, int x2, int y2, int r2)
{
	double d = sqrt(abs(x1 - x2)*abs(x1 - x2) + abs(y1 - y2)*abs(y1 - y2));
	double sr=r1>r2?r2:r1;
	double lr=r1>r2?r1:r2;
	if (d > r1 + r2) return 0;
	else if (d == r1 + r2) return 1;
	else
	{
		if (d == 0 && r1 == r2) return -1;
		else if (d == 0 && r1 != r2) return 0;
		else if (d + sr == lr) return 1;
		else if (d != 0 && d + sr < lr) return 0;
		else return 2;
	}
}

int main()
{
	int num, x1, y1, r1, x2, y2, r2;
	cin >> num;
	while (num--)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		printf("%d\n", location(x1, y1, r1, x2, y2, r2));
	}
}