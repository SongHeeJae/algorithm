#include<iostream>
using namespace std;

int main()
{
	int score;
	scanf("%d", &score);
	score /= 10;
	if (score == 9 || score == 10) printf("A");
	else if (score == 8) printf("B");
	else if (score == 7) printf("C");
	else if (score == 6) printf("D");
	else printf("F");
}