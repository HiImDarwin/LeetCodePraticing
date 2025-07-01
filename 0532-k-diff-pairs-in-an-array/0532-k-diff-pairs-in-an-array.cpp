class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      int i = 0,j = 1;
      int res = 0;
      while(j < n) {
        if(j < n && nums[j] - nums[i] < k) {
          j++;
        } else if (i <= j && nums[j] - nums[i] > k) {
          i++;
        } else if(nums[j] - nums[i] == k) {
          res++;
          while(j+1 < n && nums[j] == nums[j+1]) {
            j++;
          }
          j++;
          while(i+1 < n  && nums[i] == nums[i+1]) {
            i++;
          }
          i++;
          
        }
        while(i >= j) j++;
      }      
      return res; 
    }
};



/*
sort array
[X X X X X X]
   i j 
if nums[j] - nums[i] < k then j move right
if nums[j] - nums[i] > k then i move right
we only need unique pairs, so after match we make sure i and j wont be same value;

k can be 0 so  > i and j can't at same position but can be in same value

*/