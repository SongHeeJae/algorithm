#include <cstdio>
int main()
{
	int a,s,f=0;
	for (scanf("%d",&s);(a=getchar())-10;scanf("%d",&a),s+=f?-a:a)f=a-45?f:1;
	printf("%d",s);
}