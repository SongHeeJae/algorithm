#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> arr;
vector<int> res;
int n, a, b;

int lowerBound(int target) {
	int s = 0, e = res.size() - 1;
	while (s < e) {
		int mid = (s + e) / 2;
		if (res[mid] >= target) e = mid;
		else s = mid + 1;
	}
	return e;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n && scanf("%d %d", &a, &b); i++)
		arr.push_back({ a, b });
	sort(arr.begin(), arr.end());
	res.push_back(arr[0].second);
	for (int i = 1; i < n; i++) {
		if (arr[i].second < res[res.size() - 1])
			res[lowerBound(arr[i].second)] = arr[i].second;
		else res.push_back(arr[i].second);
	}
	printf("%d", n - res.size());
}

/*
A를 기준으로 오름차순으로 정렬했을 때,
연결된 B의 수열에서, 가장 긴 증가하는 부분 수열의 개수가 남겨야할 전깃줄의 개수입니다.
증가하는 부분 수열을 깨뜨리는 전봇대 번호가 전깃줄이 서로 교차하도록 만듭니다.

문제 예시인 8 2 9 1 4 6 7 10에서 가장 긴 증가하는 부분 수열은,
[2 4 6 7 10] 또는 [1 4 6 7 10]으로 5의 길이를 가지므로, 3개의 전깃줄을 제거해야합니다.
*/