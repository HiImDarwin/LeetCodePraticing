class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        int head=0;
        int tail=nums.size()-1;
        while(head<tail) {
            while(head<tail && nums[tail]==val) {
                tail--;
            }
            if(tail == head) break;
            if(nums[head] == val) {
                swap(nums[head],nums[tail]);
            }
            head++;
        }
        
        return nums[head]==val ? head : head+1;
    }
};