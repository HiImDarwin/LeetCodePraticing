class NumArray {
  public:
    NumArray(vector<int>& nums) {
      n_ = nums.size();
      BIT_.resize(n_ + 1, 0);
      for (int i = 0; i < n_; i++) {
        int idx = i + 1;
        update_(idx, nums[i]);
      }
    }
    
    void update(int index, int val) {
      int idx = index + 1;
      int originVal = sumRange(index, index);
      int delta = val - originVal;
      update_(idx, delta);
    }
    
    int sumRange(int left, int right) {
      return query_(right + 1) - query_(left);
    }

  private:
    void update_(int index, int delta) {
      while (index <= n_) {
        BIT_[index] += delta;
        index += (index & - index);
      }
    }

    int query_(int i) {
      int sum = 0;
      while (i > 0) {
        sum += BIT_[i];
        i -= (i & -i);
      }
      return sum;
    }
    

    int n_;
    vector<int> BIT_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

/*
BIT



*/