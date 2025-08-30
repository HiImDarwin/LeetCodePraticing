class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
      unordered_set<int> numSet(nums.begin(), nums.end());
      unordered_set<int> st, res;

      for (int& numX :nums) {
        for (int& numY :nums) {
          st.insert(numX ^ numY);
        }
      }
      for (auto& dual : st) {
        for (auto& num : nums) {
          res.insert(dual ^ num);
        }
      }

      return res.size();
    }
};