class Solution {
public:
  // bool containsDuplicate(vector<int>& nums) {
  //   unordered_set<int> s;
  //   for (const int& num : nums) {
  //     if(s.find(num) != s.end()) {
  //       return true;
  //     }
  //     s.insert(num);
  //   }    
  //   return false;
  // }
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    return numSet.size() < nums.size();
  }
};