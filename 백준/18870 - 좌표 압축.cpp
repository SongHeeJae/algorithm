#include <iostream>
#include <algorithm>
using namespace std;
int n, c = 0;
pair<int, int> arr[1000000];
int res[1000000] = { 0 };
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	sort(arr, arr + n);
	for (int i = 1; i < n; i++) {
		if (arr[i - 1].first != arr[i].first)
			res[arr[i].second] = i - c;
		else {
			res[arr[i].second] = res[arr[i - 1].second];
			c++;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", res[i]);
	}
}

/*
처음에는 set으로 중복을 제거하여 정렬한 뒤, 이진 탐색으로 좌표 압축한 결과를 찾아주었습니다.
통과는 되지만 시간이 오래 걸려서 unordered_map을 캐시로 사용하였지만 시간이 더 오래 걸렸습니다.
그래서 아래의 방법으로 바꿨습니다. 
각 값들을 인덱스 번호와 함께 오름차순으로 정렬해줍니다.
중복이 없다면 정렬된 값의 인덱스 번호가 좌표 압축한 결과이지만, 수의 중복이 있기 때문에 중복된 개수만큼 그 결과를 다시 계산해주어야합니다.
순차적으로 값을 보면서 중복되었던 값의 개수를 기억해줍니다.
정렬된 현재 값과 이전 값이 다르다면, (정렬 값의 인덱스 번호 - 중복되었던 값의 개수)가 지금 값의 좌표 압축한 결과입니다.
정렬돤 현재 값과 이전 값이 같다면, 이전 값의 좌표 압축한 결과와 동일합니다.
*/