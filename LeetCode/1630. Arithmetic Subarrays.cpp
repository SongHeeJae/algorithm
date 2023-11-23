/*
n과 m이 최대 500이기 때문에, l과 r을 이용한 하위 배열을 정렬하여 diff를 검사해주면 됩니다.
O(M * N * logN)의 시간으로 풀 수 있었습니다.
*/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res(l.size(), true);
        for(int i=0; i<l.size(); i++) {
            vector<int> temp;
            for(int j=l[i]; j<=r[i]; j++) temp.push_back(nums[j]);
            sort(temp.begin(), temp.end());

            int diff = temp[1] - temp[0];
            for(int j=2; j < temp.size(); j++) {
                if(temp[j] - temp[j - 1] != diff) {
                    res[i] = false;
                    break;
                }
            }
        }
        return res;
    }
};


/*
정렬하지 않더라도, 최댓값과 최솟값을 알면 diff를 구할 수 있습니다.
diff = (최댓값 - 최솟값) / (r[i] - l[i])
l[i], r[i] 범위 내의 어떤 수가 들어가있는지 기억하고, diff를 이용하여 값이 있는지만 확인하면 됩니다.
diff를 계산할 때 나머지가 있으면, subarray의 모든 요소가 동일한 diff를 가질 수 없습니다.
O(M * N)의 시간으로 풀 수 있었습니다.
*/

class Solution {
public:
    int chk[200001] = {0};

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res(l.size(), true);

        for(int i=0; i<l.size(); i++) {
            int mn = nums[l[i]], mx = nums[l[i]];
            for(int j=l[i]; j<=r[i]; j++) {
                chk[nums[j] + 100000] = i + 1;
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);
            }

            if(mn == mx) continue;

            int range = r[i] - l[i];
            if((mx - mn) % range) {
                res[i] = false;
                continue;
            }

            int diff = (mx - mn) / range;
            for(int j = 1; j < range; j++) {
                if(chk[mn + (j * diff) + 100000] != i + 1) {
                    res[i] = false;
                    break;
                }
            }
        }
        
        return res;
    }
};
