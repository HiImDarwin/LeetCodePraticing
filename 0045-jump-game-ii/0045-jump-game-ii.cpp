class Solution {
public:
    // DP
    // Time Complexity O(N^2)
    // int jump(vector<int>& nums) {
    //     int n= nums.size();
        
    //     vector<int> minJump(n,INT_MAX);
    //     minJump[0]=0;
    //     for(int i=0;i<n;i++) {
    //         for(int j=1;j<=nums[i];j++){
    //             if(i+j<n && minJump[i]+1 <minJump[i+j]){
    //                 minJump[i+j] = minJump[i]+1;
    //             }
    //         }
    //     }
    //     return minJump[n-1];
    // }

    int jump(vector<int>& nums) {
        int jump=0,end=0,farthest=0;
        for(int i=0; i<nums.size()-1;i++){
            farthest = max(farthest, nums[i]+i);
            if (i == end) {
              jump++;
              end = farthest;
            }
        }
        return jump;
    }

};




/*
DP


dijkstra O(n)
XXXXXXXXXX

*/