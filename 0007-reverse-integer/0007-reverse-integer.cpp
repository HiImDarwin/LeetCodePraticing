class Solution {
public:
    int reverse(int x) {
      if (x == INT_MIN) return 0;
      int sign = (x >= 0) ? 1 : -1;
      int num = 0;
      x = abs(x);
      while (x != 0) {
        int r = x % 10;
        x = x / 10;
        cout << r << " " << x << endl;
        cout << r << " " << x << endl;
        if (num > INT_MAX/10 || num == INT_MAX/10 && r > 7) {
          return 0;
        }
        num *= 10;
        num += r;
      }
      return num*sign;
    }
};