#include <iostream>
using namespace std;

string s;
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    for (int i = s.size() - 1, j = 1; i >= 0; i--, j <<= 4) {
        if (s[i] <= '9') ans += (s[i] - '0') * j;
        else ans += (s[i] - 'A' + 10) * j;
    }
    cout << ans;
}