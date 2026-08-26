class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int count = 0;
      int val;
      for (const int &num : nums) {
        if (count == 0) {
          val = num;
          count++;
        } else if (num == val) {
          count++;
        } else {
          count--;
        }
      }
      return val;
    }
};

// 4