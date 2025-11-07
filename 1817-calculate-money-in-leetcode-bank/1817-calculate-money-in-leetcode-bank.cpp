class Solution {
  public:
    int totalMoney(int n) {
      int week = n / 7;
      int sum = (28 + 28 + 7 * (week - 1)) * week / 2;
      for (int i = 0; i < n % 7; i++) {
        sum += week + i + 1;
      }
      return sum;
    }
};

/*
 1 2 3 4 5 6 7
 2 3 4 5 6 7 8
 3 4 5 6 7 8 9
 ...

  等差數列公式
  (28+28+7*n)*n / 2  = n


*/



