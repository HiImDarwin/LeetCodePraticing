class Solution {
public:
    // vector<int> nextGreaterElements(vector<int>& nums) {
    //     int n = nums.size();
    //     int i=0;
    //     bool secRound =false;
    //     vector<int> res(n,-1),st;
        
    //     for(int i=0;i<n*2;i++){
    //         int idx = i%n;
    //         while(!st.empty() && nums[idx]>nums[st.back()]){
    //             int index = st.back();
    //             st.pop_back();
    //             res[index] = nums[idx];
    //         }
    //         if(i<n) st.push_back(i);            
    //     }
    //     return res;
    // }

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
       while( !st.empty() && st.top()<=nums[i]){
             st.pop();

       }
       if( !st.empty() ) ans[i]=st.top();
       st.push( nums[i] );
       

     }
     return ans;
     }
};