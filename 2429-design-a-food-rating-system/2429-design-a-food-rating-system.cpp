
class FoodRatings {
    struct cmp{
      bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first) {
          return a.second > b.second;
        }
        return a.first < b.first;
      }
    };
    unordered_map<string, priority_queue<pair<int, string>,vector<pair<int, string>>,cmp>> cuisinesMap;
    unordered_map<string, int> foodScoreMap;
    unordered_map<string, string> foodCuisineTransfer;
    //unordered_map<string, int> lazyDelete;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
      for (int i = 0; i < foods.size(); i++) {
        foodScoreMap[foods[i]] = ratings[i];
        cuisinesMap[cuisines[i]].push({ratings[i], foods[i]});
        foodCuisineTransfer[foods[i]] = cuisines[i];
      }
    }
    
    void changeRating(string food, int newRating) {
      string cuisine = foodCuisineTransfer[food];
      if (foodScoreMap[food] == newRating) {
        return;
      }
      //lazyDelete[food]++;
      foodScoreMap[food] = newRating;
      cuisinesMap[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
      while (!cuisinesMap[cuisine].empty()) {
        string food = cuisinesMap[cuisine].top().second;
        int score = cuisinesMap[cuisine].top().first;
        if (foodScoreMap[food] == score) {
          return food;
        }
        cuisinesMap[cuisine].pop();
      }
      return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */