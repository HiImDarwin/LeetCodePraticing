class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        nums.push_back(INT_MAX);
        int n = nums.size();
        int i = 0, j = n-1;
        int res = INT_MAX;
        
        
        while(j > 0 && nums[j] >= nums[j-1]) {
          j--;
        }
        if(j == 0) return 0;


        for(int i = 0; i < n; ++i) {
          if(i != 0 && nums[i] < nums[i-1]) break;
          while(j < n && nums[i]> nums[j]) {
            j++;
          }
          res = min(res, j-i-1);
        }
        return res;
    }
};

/*

1. only can remove 1 subarray
The arr can be divided into  [0~i] [i+1~ j-1] [j~n-1]
the [i~j] is the subarry which need to be removed
So we have 3 condition
1. [0~i-1] must be non-decreasing
2. [j+1~n-1] must be non-decreasing
3. i-1 <= j+1

so we met a cornor case when [0~i] or [j~n-1] be empty satuation
beacause i and j must be an element
to solved this problem
we add to element into the array to make sure [0~i] [j~n-1] exist 

how to find i j;
use 2 pointer as window of i j
*/