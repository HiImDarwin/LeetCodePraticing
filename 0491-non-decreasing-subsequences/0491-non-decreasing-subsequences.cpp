class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> res;
        backtracking(nums,0,tmp,res);
        return res;
    }

    void backtracking(vector<int>& nums, int start, vector<int> &tmp,vector<vector<int>> &res){
        if(tmp.size()>=2) res.push_back(tmp); 
        unordered_set<int> st;
        for(int i=start;i<nums.size();i++){
            if(st.count(nums[i])) continue;
            if(!tmp.empty() && nums[i]<tmp.back()) continue;
            st.insert(nums[i]);
            tmp.push_back(nums[i]);
            backtracking(nums,i+1,tmp,res);
            tmp.pop_back();
        }
    }
};