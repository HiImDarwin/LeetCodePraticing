class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 1) return true;
        long long left = 0;
        long long right = sqrt(c);
        while(left <= right) {
            long long sumUp = left * left + right * right;
            if(sumUp == c) return true;
            else if( sumUp > c) {
              right--;
            } else {
              left++;
            }
        }
      return false;
    }
};