class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
      int res = 0;
      for (int fruitIdx = 0; fruitIdx < fruits.size(); fruitIdx++) {
        for (int i = 0; i < baskets.size(); ++i) {
          if (fruits[fruitIdx] <= baskets[i]) {
            baskets[i] = 0;
            break;
          }
          if (i == baskets.size()-1) {
            res++;
          }
        }
      }
      return res;      
    }
};

/*

 2 3 4 
 
 4 3 2

*/