/*
각 사용자마다 출발할 때의 출발지와 탑승 시간을 map에 저장해줍니다.
도착지에 도달하면, 별도의 map에 {출발지, 도착지}의 이동시간을 기록해주고,
해당 사용자의 이동 정보는 제거해줍니다.
기록된 이동시간을 이용하여 평균 시간을 계산해줍니다. 
*/

class UndergroundSystem {
public:
    map<int, pair<string, int>> track; // {탑승 아이디, {출발지, 탑승 시간}}
    
    map<pair<string, string>, vector<int>> travelTimes; // {{출발지, 도착지}, 이동시간}
    
    UndergroundSystem() { }
    
    void checkIn(int id, string stationName, int t) {
        track[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int>& pi = track[id];
        travelTimes[{pi.first, stationName}].push_back(t - pi.second);
        track.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int>& time = travelTimes[{startStation, endStation}];
        int sum = 0;
        for(int t : time) sum += t;
        return (double)sum/time.size();
    }
};


/*
요청이 들어올 때마다 이동시간 목록을 조회하여 평균 시간을 계산하는 것은 비효율적입니다.


이동시간의 총합과 개수만 저장하고, 즉시 계산할 수도 있습니다.
*/
class UndergroundSystem {
public:
    map<int, pair<string, int>> track; // {탑승 아이디, {출발지, 탑승 시간}}
    
    map<pair<string, string>, pair<int, int>> travelTimes; // {{출발지, 도착지}, {이동시간 총합, 이동시간 개수}}
    
    UndergroundSystem() { }
    
    void checkIn(int id, string stationName, int t) {
        track[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int>& startAndTime = track[id];
        pair<int, int>& sumAndCount = travelTimes[{startAndTime.first, stationName}];
        sumAndCount.first += t - startAndTime.second;
        sumAndCount.second++;
        track.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int>& pi = travelTimes[{startStation, endStation}];
        return (double)pi.first/pi.second;
    }
};


/*
출발지와 도착지 사이에 걸리는 시간은 단방향이고, 동일한 출발지에 대해 여러 도착지가 있을 수 있으니,
문자열의 중복이 나타날 여지가 있습니다.
다행히 역의 문자열 길이는 10이하이므로 크게 부담은 안되겠지만,
중복으로 인한 저장공간이 염려된다면 다음과 같이 개선할 수도 있습니다.
문자열 데이터는 별도의 map으로 관리해주는 것입니다.
연산량은 늘어나겠지만, 중복을 방지하기 때문에 저장공간을 효율적으로 활용할 수 있습니다.
*/

class UndergroundSystem {
public:
    map<int, pair<int, int>> track; // {탑승 아이디, {출발지, 탑승 시간}}
    map<pair<int, int>, pair<int, int>> travelTimes; // {{출발지, 도착지}, {이동시간 총합, 이동시간 개수}}
    
    map<string, int> dataToIndex;
    map<int, string> indexToData;
    
    UndergroundSystem() { }
    
    void checkIn(int id, string stationName, int t) {
        int index = indexDataIfNot(stationName);
        track[id] = {index, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int index = indexDataIfNot(stationName);
        pair<int, int>& startAndTime = track[id];
        pair<int, int>& sumAndCount = travelTimes[{startAndTime.first, index}];
        sumAndCount.first += t - startAndTime.second;
        sumAndCount.second++;
        track.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int>& pi = travelTimes[{getIndex(startStation), getIndex(endStation)}];
        return (double)pi.first/pi.second;
    }
    
private:
    int indexDataIfNot(string& data) {
        if(dataToIndex.find(data) != dataToIndex.end())
            return dataToIndex[data];
        int index = dataToIndex.size();
        dataToIndex[data] = index;
        indexToData[index] = data;
        return index;
    }
    
    string getData(int index) {
        return indexToData[index];
    }
    
    int getIndex(string& data) {
        return dataToIndex[data];
    }
};