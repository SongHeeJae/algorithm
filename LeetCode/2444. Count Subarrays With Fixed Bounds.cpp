/*
nums를 순차적으로 탐색하면서 유효한 subarray의 시작점과 이전의 minK와 maxK가 나타났던 지점을 기억해줍니다.
현재 탐색하는 num이 minK, maxK와 같다면, (현재 인덱스 - 시작점 인덱스 + 1)개 만큼 새로운 subarray가 만들어질 수 있습니다.
현재 탐색하는 num이 minK와 같다면, (이전의 maxK 인덱스 - 시작점 인덱스 + 1)개 만큼 새로운 subarray가 만들어질 수 있습니다.
현재 탐색하는 num이 maxK와 같다면, (이전의 minK 인덱스 - 시작점 인덱스 + 1)개 만큼 새로운 subarray가 만들어질 수 있습니다.
아직 유효한 subarray 범위지만 현재 탐색하는 num이 minK, maxK와 같지 않다면, (min(이전의 minK인덱스, 이전의 maxK인덱스) - 시작점 인덱스 + 1)개 만큼 새로운 subarray가 만들어질 수 있습니다.
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mnIdx = -1;
        int mxIdx = -1;
        long long res = 0;
        int j = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > maxK || nums[i] < minK) {
                mnIdx = -1;
                mxIdx = -1;
                j = i + 1;
                continue;
            }
            if(nums[i] == minK && nums[i] == maxK) {
                res += i - j + 1;
                mnIdx = mxIdx = i;
            } else if(nums[i] == minK) {
                if(mxIdx != -1) res += mxIdx - j + 1;
                mnIdx = i;
            } else if(nums[i] == maxK) {
                if(mnIdx != -1) res += mnIdx - j + 1;
                mxIdx = i;
            } else {
                if(mnIdx != -1 && mxIdx != -1) res += min(mxIdx, mnIdx) - j + 1;
            }
            
        }
        return res;
    }
};
