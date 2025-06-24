class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
      int n = nums.size();
      vector<int> res;
      int start = 0;
      for(int i = 0; i < n; ++i ){
        if(nums[i] != key) continue;

        int left = max(i-k,0);
        int right = min(n-1, i+k);
        while(start <= right) {
          if(start >= left) res.push_back(start);
          start++;
        }
      }
      return res;
    }
};

