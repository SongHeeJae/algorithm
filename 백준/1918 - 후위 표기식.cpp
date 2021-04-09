#include <cstdio>
char stk[30], ch;
int top = -1;
int getPriority(char op) {
	if (op == '*' || op == '/') return 2;
	else if (op == '+' || op == '-') return 1;
	else return 0;
}
int main() {
	while ((ch = getchar()) != '\n') {
		if ('A' <= ch && ch <= 'Z') printf("%c", ch);
		else {
			if (ch == ')') {
				while (stk[top] != '(') printf("%c", stk[top--]);
				top--;
			}
			else if (ch == '(') stk[++top] = ch;
			else {
				while (top != -1 && getPriority(stk[top]) >= getPriority(ch))
					printf("%c", stk[top--]);
				stk[++top] = ch;
			}
		}
	}
	while (top != -1) printf("%c", stk[top--]);
}
/*
스택을 이용하여 중위 표기식을 후위 표기식으로 변환시켜주었습니다.
*/
