class Solution {
public:
    // bool checkPossibility(vector<int>& nums) {
    //   bool modified = false;
    //   int idx=-1;
    //   for(int i=0; i < nums.size()-1; ++i) {
    //     if(nums[i+1] < nums[i]) {
    //       if(modified) return false;
    //       modified = true;
    //       idx = i+1;
    //     }
    //   }
    //   if(modified && 1<idx && idx <nums.size()-1 && nums[idx-1] > nums[idx+1] && nums[idx-2]>nums[idx])
    //     return false;
    //   return true; 
    // }
    bool checkPossibility(vector<int>& nums) {
      bool modified = false;
      for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
          if (modified) return false;
          modified = true;

          if( i > 0 && i < nums.size()-1 ) {
            if (nums[i-1]>nums[i+1]) {
              nums[i+1] = nums[i];
            } else {
              nums[i] = nums[i-1];
            }
          }
        }
      }
      return true;
    }

};