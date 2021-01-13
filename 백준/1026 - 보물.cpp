#include <iostream>
using namespace std;

int main()
{
	int num, max, min, sum = 0;
	cin >> num;
	int *A = new int[num];
	int *B = new int[num];
	int *temp = new int[num];
	int *temp2 = new int[num];
	for (int i = 0; i < num; i++) cin >> A[i];
	for (int i = 0; i < num; i++) cin >> B[i];
	for (int i = 0; i < num; i++) temp[i] = B[i];
	for (int i = 0; i < num; i++) temp2[i] = A[i];
	
	for (int i = 0; i < num; i++)
	{
		max = min = 0;
		for (int j = 1; j < num; j++)
		{
			if (temp[max] < temp[j]) max = j;
			if (temp2[min] > temp2[j]) min = j;
		}
		temp[max] = -1;
		A[max] = temp2[min];
		temp2[min] = 101;
	}
	for (int i = 0; i < num; i++) sum += A[i] * B[i];
	printf("%d", sum);

	delete[] A, B, temp, temp2;
}