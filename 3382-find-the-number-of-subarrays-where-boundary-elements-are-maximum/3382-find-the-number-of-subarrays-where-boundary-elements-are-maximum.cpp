class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
      long long res = 0;
      stack<pair<int,long long>> st;
      for(int i = 0; i< nums.size(); ++i) {
        while(!st.empty() && nums[i] > st.top().first) {
          st.pop();
        }
        if(!st.empty() && nums[i] == st.top().first) {
          st.top().second++;
          res += st.top().second;
          continue;
        } 
        res++;
        st.push({nums[i],1});
      }
      return res;
    }
};


/*
5 4 4 2 1 4 5
  ^ ^     


previous max element && element val = cur val



*/