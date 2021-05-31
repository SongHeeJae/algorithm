#include <cstdio>
#define MAX 100000
int n, arr[5000], c = 0;
bool chk[2 * MAX + 1] = { false };
int v[2 * MAX + 1] = { 0 };
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] - arr[j] > MAX || arr[i] - arr[j] < -MAX) continue;
			if (chk[arr[i] - arr[j] + MAX]) {
				c++;
				break;
			}
		}
		for (int j = v[arr[i] + MAX]; j <= i; j++) {
			if (arr[i] + arr[j] > MAX || arr[i] + arr[j] < -MAX) continue;
			chk[arr[i] + arr[j] + MAX] = true;
		}
		v[arr[i] + MAX] = i;
	}
	printf("%d", c);
}


/*
0 ~ (i-1)번까지의 임의의 세 수를 a, b, c라고 하고,
i번 수를 x라고 한다면,
a + b + c == x
a + b == x -  c 입니다.
즉, 0 ~ (i-1)번까지의 수에서 두 수의 합(a + b)으로 나올 수 있는 수가,
현재 검사하고 있는 x에서 0 ~ (i-1)번까지의 수 중 하나(c)를 뺀 값과 동일하다면,
a + b + c == x를 만들 수 있는 것입니다.

따라서, 각 i번 수(x)를 검사할 때마다 이전까지의 수 중에서 하나를 뺀 결과가 나온 적이 있는지 확인해줍니다.
그 후, x와 이전까지의 수 하나를 더하여 두 수의 합으로 나올 수 있는 값들을 표시해줍니다.

만약 중복된 x를 검사한다면, 처음부터 두 수의 합을 구해줄 필요는 없습니다.
이전에 x가 나왔던 지점을 기억하여, 그 지점부터 두 수의 합을 구해주면 됩니다.
어차피 x가 나왔던 지점까지는 이미 계산이 되어있기 때문입니다.
*/