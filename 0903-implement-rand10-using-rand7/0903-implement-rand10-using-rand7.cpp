// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
      int sum = INT_MAX;
      while (sum >= 40) {
        int a = rand7()-1;
        int b = rand7()-1;
        sum = a * 7 + b;
      }
      return 1 + sum%10; 
    }
};


/*

_ _ _ _ _ _ _ _ _ _
1 2 3 4 5 6 7 
  1 2 3 4 5 6 7
    1 2 3 4 5 6 7
      1 2 3 4 5 6 7
7       1 2 3 4 5 6 
6 7.      1 2 3 4 5
5 6 7.      1 2 3 4
4 5 6 7       1 2 3
                1 2
                  1
*/