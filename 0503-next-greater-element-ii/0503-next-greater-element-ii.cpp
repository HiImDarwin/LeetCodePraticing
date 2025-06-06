class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        bool secRound =false;
        vector<int> res(n,-1),st;
        
        for(int i=0;i<n*2;i++){
            int idx = i%n;
            while(!st.empty() && nums[idx]>nums[st.back()]){
                int index = st.back();
                st.pop_back();
                res[index] = nums[idx];
            }
            if(i<n) st.push_back(i);            
        }
        return res;
    }
};