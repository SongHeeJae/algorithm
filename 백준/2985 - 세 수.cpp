#include <iostream>
using namespace std;
int a, b, c;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b >> c;
	cout << a;
	if (a + b == c) cout << "+" << b << "=";
	else if (a - b == c) cout << "-" << b << "=";
	else if (a * b == c) cout << "*" << b << "=";
	else if (a / b == c) cout << "/" << b << "=";
	else if (a == b + c) cout << "=" << b << "+";
	else if (a == b - c) cout << "=" << b << "-";
	else if (a == b * c) cout << "=" << b << "*";
	else cout << "=" << b << "/";
	cout << c;
}