#include <cstdio>
int main()
{
	int n = 3, a, i, b;
	while (n--) {
		for (i = 4, b = 0; i-- && scanf("%d", &a);) a ? b++ : 1;
		if (b == 2) printf("B\n");
		else if (b == 3) printf("A\n");
		else if (b == 0) printf("D\n");
		else if (b == 4) printf("E\n");
		else printf("C\n");	
	}
}