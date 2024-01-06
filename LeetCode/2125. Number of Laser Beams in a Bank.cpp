/*
각 행마다 보안 장치의 개수를 세줍니다.
이전 행과 현재 행의 보안 장치로 만들어질 수 있는 레이저의 개수(=이전 행 보안 장치 개수 * 현재 행 보안 장치 개수)를 구해줍니다.
보안 장치가 없는 행은 무시합니다.
*/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalCount = 0, prevRowDeviceCount = 0;
        for(int i=0; i<bank.size(); i++) {
            int rowDeviceCount = 0;
            for(int j=0; j<bank[0].size(); j++) {
                if(bank[i][j] == '1') rowDeviceCount++;
            }
            if(rowDeviceCount != 0) {
                totalCount += prevRowDeviceCount * rowDeviceCount;
                prevRowDeviceCount = rowDeviceCount;
            }
        }
        return totalCount;
    }
};
