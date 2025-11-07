class Solution {
public:
    int smallestNumber(int n) {
      int highestOne = -1;
      for (int i = 31; i >= 0; i--) {
        if (1 << i & n) {
          highestOne = i;
          break;
        }
      }

      for (int i = 0; i < highestOne; i++) {
        n |= (1 << i);
      }
      return n;
    }
};