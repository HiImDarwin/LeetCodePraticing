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
        int n=nums.size();
        vector<int> res(n,-1);
        stack<int> st;
        
        for(int i=2*n-1; i>=0;--i) {
            int idx = i%n;

            while(!st.empty() && st.top()<=nums[idx]) {
                st.pop();
            }
            if(i<n) {
                if(!st.empty()) {
                    res[idx] = st.top();
                }
            }

            st.push(nums[idx]);
        }
        return res;
    }
};