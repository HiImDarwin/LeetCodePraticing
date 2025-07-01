class Solution {
public:
    int triangleNumber(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      int res = 0;
      for (int i = 0; i< n-2; i++) {
        for(int j = i + 1; j < n-1; j++) {
          for(int k = j + 1; k < n; k++) {
            if(nums[i] + nums[j] <= nums[k]) break;
            res++;
          }
        }
      }
      return res;
    }
};


/*
for triangel to short side sum must bigger than the longest side 
a + b > c

so we have i j k three pointer
fixed i can use for for add 1 per round
in each round j and k  run throuh whole matrix

In this case. We want to ask if the element in array is length or link
*/