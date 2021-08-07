#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2147483647
using namespace std;

int n, h[600], ans = INF;

vector<pair<int, pair<int, int>>> arr;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			arr.push_back({ h[i] + h[j], {i, j} });
		}
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i].second.first == arr[i - 1].second.first
			|| arr[i].second.first == arr[i - 1].second.second
			|| arr[i].second.second == arr[i - 1].second.first
			|| arr[i].second.second == arr[i - 1].second.second) continue;
		ans = min(ans, arr[i].first - arr[i - 1].first);
	}
	printf("%d", ans);
}

/*
만들 수 있는 눈사람의 가중치를 사용된 눈덩이와 함께 기억하여 오름차순으로 정렬해줍니다.
서로 다른 눈덩이로만 이루어져 있으면서 인접해있는 눈사람들을 검사하면서 그 차이가 최소가 되는 값을 찾아줍니다.



처음 풀이했던 방식은,
먼저 눈덩이들을 정렬하고, 하나의 눈사람을 만들기 위한 두 개의 눈덩이를 미리 지정해놓은 뒤,
투 포인터를 이용하여 지정해둔 두 눈덩이와 새로운 두 개의 눈덩이의 차이가 최소가 되는 값을 찾아주었습니다.

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 2147483647
using namespace std;

int n, h[600], ans = INF;

void cal(int i, int j) {
	int val = h[i] + h[j], l = 0, r = n - 1;
	while (l < r) {
		if (l == i || l == j) {
			l++;
			continue;
		}
		if (r == i || r == j) {
			r--;
			continue;
		}
		ans = min(ans, abs(val - (h[l] + h[r])));
		if (h[l] + h[r] > val) {
			r--;
		}
		else {
			l++;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}

	sort(h, h + n);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cal(i, j);
		}
	}

	printf("%d", ans);
}
*/