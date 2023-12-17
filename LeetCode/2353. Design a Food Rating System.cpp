/*
map과 set으로 각 cuisine 별 rating/food 쌍을 저장해줍니다.
set을 이용하면 정렬 상태를 유지하고 있기 때문에, 처음 순회되는 값으로 highest-rated food를 찾을 수 있습니다.
rating이 변화될 때마다 위 구조를 수정해줘야하므로, 각 food의 cuisine과 rating도 기억해줍니다.
map은 정렬 상태가 필요 없으므로 unordered_map을 사용합니다.
*/

class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> m;
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++) {
            m[cuisines[i]].insert({-ratings[i], foods[i]});
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string& cuisine = foodToCuisine[food];
        int curRating = foodToRating[food];
        foodToRating[food] = newRating;

        m[cuisine].erase({-curRating, food});
        m[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return m[cuisine].begin()->second;
    }
};



/*
위 코드에서는 map을 이용하여 각 food의 cuisine과 rating을 기억해주었습니다.
food의 기존 인덱스와 cuisines, ratings 데이터를 가지고 있는다면, map 대신 vector(또는 배열)로 각 food의 cuisine과 rating을 찾을 수 있습니다.
*/

class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> m;
    vector<string> cuisines;
    vector<int> ratings;
    unordered_map<string, int> foodIdx; 

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++) {
            m[cuisines[i]].insert({-ratings[i], foods[i]});
            this->cuisines.push_back(cuisines[i]);
            this->ratings.push_back(ratings[i]);
            this->foodIdx[foods[i]] = i;
        }
    }
    
    void changeRating(string food, int newRating) {
        int idx = foodIdx[food];
        
        m[cuisines[idx]].erase({-ratings[idx], food});
        m[cuisines[idx]].insert({-newRating, food});

        ratings[idx] = newRating;
    }
    
    string highestRated(string cuisine) {
        return m[cuisine].begin()->second;
    }
};

