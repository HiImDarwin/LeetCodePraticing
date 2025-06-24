class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
      int n = nums.size();
      set<int> idxSet;
      for(int i = 0; i < n; ++i ){
        if(nums[i] != key) continue;
        int idx = i - k >=0 ? i - k : 0;
        while(idx <= i+k && idx < n) {
          idxSet.insert(idx);
          idx++;
        }
      }
      vector<int> res(idxSet.begin(), idxSet.end());
      return res;
    }
};