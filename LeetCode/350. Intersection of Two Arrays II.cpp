/*
count map을 이용하여 풀었습니다.
*/

class Solution {
public:
    int cnt[1001] = {0};
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& smaller = nums1.size() < nums2.size() ? nums1 : nums2;
        vector<int>& larger = nums1.size() < nums2.size() ? nums2 : nums1;

        for(int val : smaller) {
            cnt[val]++;
        }

        vector<int> res;
        for(int val : larger) {
            if(cnt[val]-- > 0) {
               res.push_back(val); 
            }
        }
        return res;
    }
};

/*
What if nums1's size is small compared to nums2's size? Which algorithm is better?
nums1의 크기가 nums2보다 작다면, nums1에 대해서 count map을 초기화하는게 더 나을 수 있습니다.
nums2가 nums1의 요소를 모두 다 가진다면, 교집합의 크기가 nums1의 크기가 동일한다면, nums2 순회를 즉시 끝마칠 수도 있습니다.
또, 지금은 count 배열을 이용했지만, 별도 map을 정의한다면, nums1에 대한 map 초기화가 더 작은 공간을 차지할 수도 있습니다.
그런데 이 부분은 값의 분포에 관한 문제라, 단순 요소의 개수로 판별하긴 애매한 부분으로 보입니다.
외의 이점은 잘 모르겠네요.

What if the given array is already sorted? How would you optimize your algorithm?
주어진 두 배열이 모두 정렬되어있다면, 별도 추가 공간 없이 투포인터를 이용하여 O(1)의 공간, O(N)의 시간으로 풀 수 있습니다.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++, j++;
            } else if(nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};

/*
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
nums2가 너무 크고 메모리 제한이 있다면, nums2를 메모리로 일부만 가져와서 처리하는 방법이 있겠습니다.
nums1에 대해서만 count map을 초기화한 뒤 nums2를 순회하면서 검사한다.
nums2를 external merge sort 등의 방법으로 디스크에서 정렬된 상태를 가질 수 있도록 한다. 등..
*/
