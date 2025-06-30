class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      int n = nums2.size();
      vector<int> res;
      unordered_map<int,int> mp; //num next greater
      stack<int> st;
      for(int i = n-1; i >= 0; --i) {
        while(!st.empty() && nums2[i] > st.top()){
            st.pop();
        }
        if(st.empty())  mp[nums2[i]] = -1;
        else            mp[nums2[i]] = st.top();

        st.push(nums2[i]);
      }

      for(int num : nums1) {
        res.push_back(mp[num]);
      }

      return res;
    }
};


/*
abcde
axbxxcdxe
find nums1 element in num 2 
find next greater element of nums2 

speedup
record the pos of nums2 in map

*/