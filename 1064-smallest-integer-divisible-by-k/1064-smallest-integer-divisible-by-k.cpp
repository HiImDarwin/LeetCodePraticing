class Solution {
public:
    int smallestRepunitDivByK(int k) {
      if (k%2 == 0) return -1;
      int num = 0;
      int len = 0;
      unordered_set<int> remainder;
      do {
        num *= 10;
        num += 1;
        num = num % k;
        if (remainder.find(num) != remainder.end()) {
          return -1;
        }
        remainder.insert(num);
        len++;
      } while (num != 0);

      return len;

      
    }
};

/*

1...1
11...4
111....6
1111....5
11111

*/