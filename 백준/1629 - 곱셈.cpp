#include <iostream>
#define ll long long int
ll remainder(ll a, ll b, ll c) {
	if (b == 1) return a % c;
	ll res = remainder(a, b / 2, c) % c;
	return (b % 2 ? ((res * res)%c) * a : res * res) % c;
}
int main() {
	ll a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld\n", remainder(a, b, c));
}