#include <iostream>
#include <vector>
using namespace std;

int diff = 987654321;

void teamAbility(int nums[][20], bool team[20], int n, int c, int count) {
	
	if (c > n) return;
	if (count == n/2) {
		int start=0, link=0;
		for (int i = 0; i < n; i++) {
			if (team[i]) {
				for (int j = 0; j < n; j++)
					if (team[j]) start += nums[i][j];
			}
			else {
				for (int j = 0; j < n; j++)
					if (!team[j]) link += nums[i][j];
			}
		}
		diff = abs((start - link)) < diff ? abs((start - link)) : diff;
		return;
	}

	teamAbility(nums, team, n, c + 1, count);
	team[c] = true;
	teamAbility(nums, team, n, c + 1, count + 1);
	team[c] = false;
}

int main() {
	int n;
	scanf("%d", &n);
	int nums[20][20];
	bool team[20] = { false, }; // 스타트팀
	for (int i = 0; i < n; i++) 
		for(int j=0; j<n; j++)
			scanf("%d", &nums[i][j]);

	teamAbility(nums, team, n, 0, 0);

	printf("%d\n", diff);

}