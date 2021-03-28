#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> arr;
vector<int> res, record;
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
	record.push_back(0);
	for (int i = 1; i < n; i++) {
		if (arr[i].second < res[res.size() - 1]) {
			int idx = lowerBound(arr[i].second);
			res[idx] = arr[i].second;
			record.push_back(idx);
		}
		else {
			record.push_back(res.size());
			res.push_back(arr[i].second);
		}
	}
	int val = res.size() - 1;
	for (int i = record.size() - 1; i >= 0; i--) {
		if (val == record[i]) {
			arr[i].first = -1;
			val--;
		}
	}
	
	printf("%d\n", n - res.size());
	for (int i = 0; i < arr.size(); i++)
		if (arr[i].first != -1) printf("%d\n", arr[i].first);
}

/*
​
전깃줄 시리즈에서 가장 긴 증가하는 부분 수열의 개수가 남겨야할 전깃줄의 개수였습니다.
이번 문제에서는 가장 긴 증가하는 부분 수열의 각 요소 값이 무엇인지도 확인해줄 필요가 있습니다.
일단 입력 값을, A를 기준으로 오름차순 정렬하면 다음과 같습니다.

8
1 8
2 2
3 9
4 1
6 4
7 6
9 7
10 10

가장 긴 증가하는 부분 수열의 개수를 구하기 위해 배열 arr1과 arr2를 두겠습니다.
arr1은 현재 검사하고 있는 원본 배열 요소가 arr1의 끝 원소보다 크다면 그대로 넣어주고,
arr1의 끝 원소보다 작다면 lower bound를 이용해서 해당 원소보다 처음으로 큰 값이 나오는 위치에 넣어줄 것입니다.
또, arr2는 원본 배열 요소가 arr1의 몇 번 인덱스에 저장되는지 기억해줄 것입니다.
원본 배열인 B 전봇대의 요소는 arr0 = [8 2 9 1 4 6 7 10]으로 정의해두겠습니다.

arr0 : [8, 2, 9, 1, 4, 6, 7, 10]
arr1 : []
arr2 : []
  - 현재 요소 8 : arr1 배열이 비어있으므로 0번 인덱스에 그대로 삽입.
arr0 : [8, 2, 9, 1, 4, 6, 7, 10]
arr1 : [8]
arr2 : [0]
  - 현재 요소 2 :arr1  배열의 끝 요소인 8보다 작으므로 lower bound 수행. 0번 인덱스 2로 변경
arr0 : [8, 2, 9, 1, 4, 6, 7, 10]
arr1 : [2]
arr2 : [0, 0]
  - 현재 요소 9 : arr1 배열의 끝 요소인 9보다 크므로 배열의 끝인 1번 인덱스에 삽입
arr0 : [8, 2, 9, 1, 4, 6, 7, 10]
arr1 : [2, 9]
arr2 : [0, 0, 1]
  - 현재 요소 1 : arr1 배열의 끝 요소인 9보다 작으므로 lower bound 수행. 0번 인덱스 1로 변경
arr0 : [8, 2, 9, 1, 4, 6, 7, 10]
arr1 : [1, 9]
arr2 : [0, 0, 1, 0]
  - 현재 요소 4 : arr1 배열의 끝 요소인 9보다 작으므로 lower bound 수행. 1번 인덱스 4로 변경
arr0 : [8, 2, 9, 1, 4, 6, 7, 10]
arr1 : [1, 4]
arr2 : [0, 0, 1, 0, 1]
  - 현재 요소 6 : arr1 배열의 끝 요소인 4보다 크므로 배열의 끝인 2번 인덱스에 삽입
arr0 : [8, 2, 9, 1, 4, 6, 7, 10]
arr1 : [1, 4, 6]
arr2 : [0, 0, 1, 0, 1, 2]
  - 현재 요소 7 : arr1 배열의 끝 요소인 6보다 크므로 배열의 끝인 3번 인덱스에 삽입
arr0 : [8, 2, 9, 1, 4, 6, 7, 10]
arr1 : [1, 4, 6, 7]
arr2 : [0, 0, 1, 0, 1, 2, 3]
  - 현재 요소 10 : arr1 배열의 끝 요소인 7보다 크므로 배열의 끝인 4번 인덱스에 삽입
arr0 : [8, 2, 9, 1, 4, 6, 7, 10]
arr1 : [1, 4, 6, 7, 10]
arr2 : [0, 0, 1, 0, 1, 2, 3, 4]

이로써 arr1은 4번 인덱스까지 길이 5의 배열이 만들어졌습니다.
arr2를 역순으로 뒤집어보면, [4, 3, 2, 1, 0, 1, 0, 0]이 됩니다.
arr1의 마지막 인덱스 번호부터 시작하여 순차적으로 내려가는 값은,
원본 배열 arr0에서 가장 긴 증가하는 부분 수열의 인덱스 값이 됩니다.

구해야할 것은, 제거시켜야 할 전깃줄의 A 전봇대 번호입니다. 
가장 긴 증가하는 부분을 제외시킨 뒤, 남은 부분의 A 전봇대 번호를 출력해주면 됩니다.
arr2에서 순차적으로 내려가는 수열은 [4, 3, 2, 1, 0]이므로,
이 부분을 제외한 arr0은 [8, 2, 9, X, X, X, X, X]가 됩니다.
기존에 입력받은 전깃줄 배열은 A를 기준으로 오름차순 정렬되어있으므로,
(남아있는 arr0 요소들의 인덱스 번호 + 1)이 제거해야할 전깃줄의 A 전봇대 번호입니다.


코드에서 arr1의 역할은 res가 담당하고, arr2의 역할은 record가 담당합니다.
*/