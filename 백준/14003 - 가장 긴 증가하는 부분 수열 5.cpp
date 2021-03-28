#include <iostream>
#include <vector>
using namespace std;
vector<int> arr, res, record, ans;
int n, a;

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
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		arr.push_back(a);
	}
	res.push_back(arr[0]);
	record.push_back(0);
	for (int i = 1; i < n; i++) {
		if (arr[i] <= res[res.size() - 1]) {
			int idx = lowerBound(arr[i]);
			res[idx] = arr[i];
			record.push_back(idx);
		}
		else {
			record.push_back(res.size());
			res.push_back(arr[i]);
		}
	}

	int val = res.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (val == record[i]) {
			ans.push_back(arr[i]);
			val--;
		}
	}
	
	printf("%d\n", ans.size());
	for (int i = ans.size() - 1; i >= 0; i--)
		printf("%d ", ans[i]);
}

/*
풀이는 아래와 동일합니다.
https://blog.naver.com/gmlwo308/222290802333

하지만 동일한 방법으로는 통과가 안됐었는데, 이 경우에는 위 문제와 달리 중복된 값이 있었기때문입니다.
현재 배열 요소 값을 lower bound로 채워나가고 있는 배열의 끝 값과 비교할 때, 등호를 넣어주니 통과되었습니다.
"증가"하는 부분 수열이기 때문에, 동일한 값에 대해서는 그 자리를 다시 메꿔줘야 했습니다.
*/