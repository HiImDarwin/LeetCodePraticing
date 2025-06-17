class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 1) return true;
        int left = 0;
        int right = sqrt(c);
        while(left <= right) {
            long long sumUp = 1LL * left * left + 1LL * right * right;
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