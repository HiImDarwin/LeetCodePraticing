class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHp(nums.begin(),nums.end());
        for(int i=1;i<k;i++) {
            maxHp.pop();
        } 
        return maxHp.top();
    }
};