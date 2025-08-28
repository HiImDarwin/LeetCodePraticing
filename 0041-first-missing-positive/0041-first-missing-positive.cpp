class Solution {
public:
    // int firstMissingPositive(vector<int>& nums) {
    //   nums.insert(nums.begin(),0);
    //   for(int i = 0; i< nums.size(); ++i) {
    //     while(nums[i]!= i && nums[i] < nums.size() && nums[i]!=nums[nums[i]])
    //       swap(nums[i],nums[nums[i]]);
    //   }
    //   for(int i = 0; i<nums.size(); ++i) {
    //     if(nums[i] != i) return i;
    //   }
    //   return nums.size();
    // }

    int firstMissingPositive(vector<int>& nums) {
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        if (nums[i] <= 0) {
          continue;
        }
        while (0 < nums[i] && nums[i] < n && nums[nums[i]-1] != nums[i]) {
          swap(nums[i], nums[nums[i] - 1]);
        }
      }

      for (int i = 0; i < n; i++) {
        if (nums[i]!= i + 1) return i + 1;
      }
      return n + 1;
    }
};
/*
find smallest positive int didn't in nums

n nums 
1 <= ans <= n+1

done in O(n) time
nums not sorted
if num n not in index n-1 than the num is the result


*/