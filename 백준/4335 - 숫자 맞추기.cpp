#include <cstdio>
int a, i;
bool v[10];
int main() {
	while (scanf("%d", &a) && a-- && scanf("%*s %c%*s", &++i)) {
		if (i == 'h') for (i = a; i < 10; i++) v[i] = 1;
		else if (i == 'l') for (i = a; i >= 0; i--) v[i] = 1;
		else {
			printf("Stan %shonest\n", v[a] ? "is dis" : "may be ");
			for (i = 0; i < 10; i++)v[i] = 0;
		}
	}
}

/*
값이 나올 수 없는 위치를 체크해두고, "right on"일 때의 숫자가 나올 수 없는 위치라면 거짓말을 한 것입니다.

괜히 라인 수 줄여보다가 이상하게? 많은 걸 배울 수 있었습니다.

1. scanf에서 "%*s" 이런 식으로 하면, 해당하는 부분은 입력을 무시하고 넘어갈 수가 있었습니다.

2. scanf에서 int형에 %c로 받으려고 할때, 그 변수가 음수라면 입력값의 오류가 있었습니다. 그런데 0 이상의 수는 올바르게 입력이 됩니다.
예를 들어, int a = - 1; scanf("%c", &a);는 입력이 제대로 안되지만, int a = 0;으로 초기화하고 입력받으면, 정상적으로 입력이 받아집니다. 원래 이렇게 하면 안되겠지만, character형의 범위에 영향을 받는건지 원인은 잘 모르겠습니다.

3. bool은 따로 초기화 안해줘도 false로 초기화가 됩니다.

*/