#include <iostream>
using namespace std;

typedef long long ll;

int n, m;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

void fraction(ll& a, ll& b) {
	ll g = gcd(a, b);
	a /= g, b /= g;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll a, b, aa, bb;
	cin >> n >> a >> b;
	fraction(a, b);
	while (--n) {
		cin >> aa >> bb;
		fraction(aa, bb);
		a = gcd(a, aa);
		b = lcm(b, bb);
	}
	cout << a << " " << b;
}

/*
분자의 최소공배수와 분모의 최대공약수를 구해주면 최대 코인 단위를 구할 수 있습니다.
주의할 점은, 주어지는 아이템의 가격은 기약분수 형태가 아닐 수 있기 때문에,
기약분수형태로 만들어준 뒤에 최소공배수와 최대공약수를 구해주어야합니다.
*/