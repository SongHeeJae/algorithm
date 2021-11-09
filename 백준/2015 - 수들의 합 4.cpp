#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long ll;

unordered_map<int, ll> cnt;
int sum[200001];
int n, k, a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
        cin >> sum[i];
		sum[i] += sum[i - 1];
		ans += cnt[sum[i] - k] + (sum[i] == k);
		cnt[sum[i]]++;
	}
	cout << ans;
}