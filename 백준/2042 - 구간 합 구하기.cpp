#include <iostream>
#include <cmath>
#include <vector>
using std::vector;

long long init(vector<long long> &data, vector<long long> &seg, int i, int s, int e)
{
	if (s == e) seg[i] = data[s];
	else seg[i] = init(data, seg, i*2+1, s, (s + e) / 2) + init(data, seg, i*2+2, (s + e) / 2 + 1, e);
	return seg[i];
}

void update(vector<long long> &seg, long long diff, int i, int s, int e, int ci)
{
	if (s <= ci && ci <= e)
	{
		seg[i] += diff;

		if (s != e)
		{
			update(seg, diff, i * 2 + 1, s, (s + e) / 2, ci);
			update(seg, diff, i * 2 + 2, (s + e) / 2 + 1, e, ci);
		}
	}
}

long long sum(vector<long long> &seg, int i, int s, int e, int l, int r)
{
	if (l > e || r < s) return 0;
	else if (l <= s && e <= r) return seg[i];
	else return sum(seg, i * 2 + 1, s, (s + e) / 2, l, r) + sum(seg, i * 2 + 2, (s + e) / 2 + 1, e, l, r);
}

int main()
{
	int n, m, k, a, b, c;
	long long t;

	scanf("%d %d %d", &n, &m, &k);
	int tree_size = pow(2, (int)log2(n) + 2);

	vector<long long> seg(tree_size);
	vector<long long> data;

	for (int i = 0; i < n && scanf("%lld", &t); i++) data.push_back(t);

	init(data, seg, 0, 0, n - 1);
	
	for (int i = 0; i < m + k; i++)
	{
		scanf("%d %d", &a, &b);
		if (a == 1) // 수의 변경
		{
			long long c;
			scanf("%lld", &c);
			update(seg, c-data[b-1], 0, 0, n - 1, b-1);
			data[b - 1] = c;
		}
		else // 합 출력
		{
			int c;
			scanf("%d", &c);
			printf("%lld\n", sum(seg, 0, 0, n - 1, b - 1, c - 1));
		}
	}
}