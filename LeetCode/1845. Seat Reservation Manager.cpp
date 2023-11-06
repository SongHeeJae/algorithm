/*
min heap을 사용하여 풀 수 있었습니다.
예약 해제된 seatNumber는 min heap에 넣어줍니다.
예약되었던 seatNumber의 최댓값을 기억해줍니다.
예약 해제되었다는 것은 이미 예약되었던 seatNumber의 최댓값보다 작음을 의미합니다.
min heap에 seatNumber가 있으면 예약 해제되었던 해당 좌석을 예약해주고, 그렇지 않다면 새로운 좌석을 예약해주고 seatNumber의 최댓값을 업데이트해줍니다.
*/

class SeatManager {
public:
    priority_queue<int> pq;
    int maxReservedSeatNumber = 1;
    SeatManager(int n) {
 
    }
    
    int reserve() {
        if(!pq.empty()) {
            int res = -pq.top(); pq.pop();
            return res;
        }
        return maxReservedSeatNumber++;
    }
    
    void unreserve(int seatNumber) {
        pq.push(-seatNumber);
    }
};
