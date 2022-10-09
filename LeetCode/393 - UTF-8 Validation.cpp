class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for(int i=0; i<data.size(); i++) {
            if(cnt == 0) {
                if(((data[i] >> 7) & 1)) {
                    for(int j=6; j>=0; j--) {
                        int val = (data[i] >> j) & 1;
                        if(val == 0) break;
                        cnt++;
                    }
                    if(cnt == 0 || cnt > 3) return false;      
                } 
            } else {
                cnt--;
                if(((data[i] >> 6) & 3) != 2) // mask bits 11, last 2 bits 10
                    return false;
            }
        }
        return cnt == 0;
    }
};
