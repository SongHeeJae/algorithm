#include <iostream>
#include <vector>
#define N_MAX 30
#define W_MAX 500
#define NW_MAX N_MAX * W_MAX
#define B_MAX 40000
using namespace std;

int n, m, b, weight[N_MAX];
bool dp[B_MAX + 1];
bool chk[B_MAX + 1];
vector<int> t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> weight[i];

	dp[0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = B_MAX; j >= weight[i]; j--) {
			if (!dp[j] && dp[j - weight[i]]) {
				dp[j] = true;
				t.push_back(j);
			}
		}
	}

	for (int i : t) {
		if (i > 15000) continue;
		for(int j : t) {
			if (j - i <= 0) continue;
			chk[j - i] = chk[j] = true;
		}
	}

	cin >> m;
	while (m--) {
		cin >> b;
		cout << (chk[b] ? 'Y' : 'N') << " ";
	}
}

/*
배낭 문제와 비슷하게 다이나믹 프로그래밍을 이용하여 풀이하였습니다.
먼저 주어진 추들을 이용하여 만들 수 있는 모든 무게 조합을 구해줍니다.
중복으로 적용되는 것을 방지하기 위하여 역순으로 반복문을 수행해줍니다.

모든 추들의 무게 조합을 구했으면, 이제 무게를 확인할 수 있는 구슬의 무게들을 구해야합니다.
일단 지금 구한 추 조합의 무게를 가지는 구슬들은 모두 확인할 수 있습니다.
추 조합은, 양팔저울의 한쪽에 모두 올라가있는 무게라고 볼 수 있습니다.
그렇다면, 다른 한쪽에는 구슬 1개와 추 0~x개를 함께 올릴 수 있습니다.

즉, 추들만 올라가있는 한쪽에서 추를 일부 다른 한쪽으로 옮겨둔 모든 상황에 수평을 이룰 수 있는 구슬의 무게를 생각하면, 무게를 확인할 수 있는 모든 구슬의 무게들을 구할 수 있습니다.

위 예시로 판단해보면,
한 쪽에 추들이 5만큼 올라가있다면, 그 쪽에서 임의의 추 몇 개를 다른 한 쪽으로 옮겨줍니다.
만약 무게 2의 추를 옮겼다면, 양 쪽의 무게는 각각 3과 2가 됩니다.
따라서, 양 쪽의 무게 차이는 무게 1의 구슬을 올리면 수평을 맞출 수 있습니다.

한쪽에 추들이 8만큼 올라가있다면, 그 쪽에서 임의의 추 몇 개를 다른 한 쪽으로 옮겨줍니다.
만약 무게 3의 추와 무게 3의 추를 옮겼다면, 양 쪽의 무게는 각각 6과 2가 됩니다.
따라서, 양 쪽의 무게 차이는 무게 4의 구슬을 올리면 수평을 맞출 수 있습니다.

추의 개수는 30개이고, 추의 최대 무게는 500이기 때문에, 모든 추 무게의 합은 15000이 됩니다.
이를 이용하여 무게 15000까지 만들어낼 수 있는 추 조합을 검사하며,
한 쪽에 올려져있는 추 조합의 일부를 다른 한 쪽으로 옮겼을 때의, 양 쪽의 무게 차이를 구해주었습니다.
그렇다면, 이 모든 무게 차이가 확인할 수 있는 구슬의 무게가 됩니다. 
1. 추들이 한쪽에 다 올려져있을 때, 이미 확인할 수 있는 무게 j
2. j에서 무게 i만큼을 가지는 추의 일부를 다른 한쪽으로 옮겼을 때, 양 쪽의 무게차이 j - i
결국 이 두 가지가 확인 할 수 있는 구슬의 무게입니다.
*/