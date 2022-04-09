/*
최소 힙에 k개의 원소만 유지해줍니다.
그러면 k번째 큰 수보다 작은 수는 모두 제거되기 때문에, 최소 힙의 top은 k번째 큰 수가 유지될 수 있습니다.
*/

class KthLargest {
private:
    int k;
    priority_queue<int> pq;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for(int num : nums) pq.push(-num);  
        while(pq.size() > k) pq.pop();
    }
    int add(int val) {
        pq.push(-val);
        if(pq.size() > k) pq.pop();
        return -pq.top();
    }
};