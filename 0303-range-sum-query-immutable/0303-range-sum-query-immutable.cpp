class NumArray {
public:
    NumArray(vector<int>& nums) : prefixSum(nums.size()), n(nums.size()){     
        prefixSum[0] = nums[0];
        for(int i=1;i<n;++i) {
            prefixSum[i] = nums[i]+prefixSum[i-1];
        }   
    }
    
    int sumRange(int left, int right) {
        if(left==0) return prefixSum[right];
        return prefixSum[right]-prefixSum[left-1];
        
    }
private:
    vector<int> prefixSum;
    int n;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */