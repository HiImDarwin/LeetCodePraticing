class Solution {
public:
    int jump(vector<int>& nums) {
        int n= nums.size();
        
        vector<int> minJump(n,INT_MAX);
        minJump[0]=0;
        for(int i=0;i<n;i++) {
            for(int j=1;j<=nums[i];j++){
                if(i+j<n && minJump[i]+1 <minJump[i+j]){
                    minJump[i+j] = minJump[i]+1;
                }
            }
        }
        return minJump[n-1];
    }
};