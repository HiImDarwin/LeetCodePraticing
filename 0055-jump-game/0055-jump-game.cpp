class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable=0;
        bool reach=false;
        for(int i=0; i<=n-1 && i<=reachable ;i++){
            reachable=max(reachable,i+nums[i]);
            if(i+nums[i]>=n-1){
                reach = true;
                break;
            }
        }
        return reach;
        
    }
};