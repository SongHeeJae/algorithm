/*
최종 도착점이 아니라면, 반드시 출발점도 있어야합니다. 
모든 출발점을 set에 담아주고, 각 도착점이 출발점이었는지 확인해줍니다.
*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> cities;

        for(auto& path : paths) {
            cities.insert(path[0]);
        }

        for(auto& path : paths) {
            if(!cities.contains(path[1])) return path[1];
        }

        return "";
    }
};
