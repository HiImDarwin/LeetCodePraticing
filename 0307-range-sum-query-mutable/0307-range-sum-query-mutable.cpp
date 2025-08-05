class NumArray {
    vector<int> indexTree;
    vector<int> nums;
    int n;
public:
    NumArray(vector<int>& nums) {
      n = nums.size();
      this->nums = nums;
      indexTree.assign(n+1, 0);
      for (int i = 1; i <= n; i++) {
        indexTree[i] += nums[i - 1];
        int j = i + (i & -i);
        if (j <= n) {
          indexTree[j] += indexTree[i];
        }
        // update(i, nums[i]);
      }
    }
    
    void update(int index, int val) {
      int delta = val - nums[index];
      int idx = index + 1;
      while (idx <= n) {
         indexTree[idx] += delta;
         idx = idx + (idx & -idx);
      }
      nums[index] = val;
    }
    
    int sumRange(int left, int right) {
      return prefixSum(right) - prefixSum(left-1);
    }

    int prefixSum(int index) {
      int res = 0;
      int idx = index + 1;
      while (idx > 0) {
        res += indexTree[idx];
        idx = idx - (idx & -idx);
      }
      return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */