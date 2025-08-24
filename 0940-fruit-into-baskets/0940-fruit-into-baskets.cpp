class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int n = fruits.size();
      int fruitA = -1;
      int amountA = 0;
      int fruitB = -1;
      int amountB = 0;
      int total = 0;
      int i = 0;
      int res = 0;
      while (i < n) {
        if (fruits[i] != fruitA && fruits[i] != fruitB) {
          res = max(res,total);
          fruitB = fruitA;
          amountB = amountA;
          fruitA = fruits[i];
          amountA = 1;
          total = amountA + amountB;
        } else if (fruits[i] != fruitA && fruits[i] == fruitB) {
          swap(amountA, amountB);
          swap(fruitA, fruitB);
          amountA = 1;
          total++;
        } else if (fruits[i] == fruitA) {
          amountA++;
          total++;
        }
        i++;
      }
      res = max(res,total);
      return res;
    }
};

/*

1 2 3 1 222 3333 222 333 11 2
    


segment 

*/