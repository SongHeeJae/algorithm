#include <iostream>

int n;
long long int arr[100];
bool visit[100] = { false };
long long int a[100];
void dfs(long long int c) {

	if (c == n) {
		for (int i = 0; i < n; i++)
			printf("%lld ", a[i]);
		exit(0);
	}

	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;
		long long int j = a[c-1];
		if (j % 3 == 0) {
			j /= 3;
			if (j != arr[i]) j = j * 6;
		}
		else j *= 2;
		if (j != arr[i]) continue;
		visit[i] = true;
		a[c] = arr[i];
		dfs(c + 1);
		visit[i] = false;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		a[0] = arr[i];
		dfs(1);
		visit[i] = false;
	}
}

/*
조건에 맞는 수열을 만들어내고, n개의 수열이 만들어지면 출력 후에 종료시켜줬습니다.
자꾸 시간초과가 나는 이유를 몰랐는데, 수의 범위를 간과하고 있었네요. long long int로 바꿔주니 해결되었습니다.
*/