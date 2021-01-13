#include <iostream>
int main()
{
	int n,a=0,b=0,c;
	for (scanf("%d",&n),getchar();n--;printf("%d\n",a),a=b=0)
		while ((c=getchar())!='\n')c=='O'?a+=++b:b=0;
}