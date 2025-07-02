class Solution {
  vector<int> res;
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        res.resize(n,0);
        auto sorted = nums;

        helper(nums, sorted ,0 , n-1);
        return res;
    }

    void helper(vector<int> & nums,vector<int>& sorted, int a, int b) {
      if(a >= b) return;
      // divide
      int mid = a + (b - a) / 2;
      helper(nums, sorted, a, mid);
      helper(nums, sorted, mid+1, b);
      // conquer
      for(int i = a; i <= mid; i++) {
         auto iter = lower_bound(sorted.begin()+mid+1, sorted.begin()+b+1, nums[i]);
         res[i] += iter - (sorted.begin()+mid+1);
      }
      //combine
      sort(sorted.begin()+a,sorted.begin()+b+1);
    }
};


/*
  Consider the devide  conquer and combine
  [O O O O O O O O O O O O]
  [A A A A A ] [B B B B B B] 
  When combine if we can let B be ordered, 
  than the searching for each a can use Binary Search
*/