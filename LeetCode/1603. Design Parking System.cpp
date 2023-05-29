/*
타입에 따른 주차장 크기를 기억해두고, 타입별 차가 주차될 때 마다 확인해줍니다.
*/

class ParkingSystem {
public:
    int p[4] = {0};
    ParkingSystem(int big, int medium, int small) {
        p[1] = big, p[2] = medium, p[3] = small; 
    }
    
    bool addCar(int carType) {
        if(!p[carType]) return false;
        p[carType]--;
        return true;
    }
};


