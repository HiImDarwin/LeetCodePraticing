class Solution {
  int res;
public:
    int binarySearchableNumbers(vector<int>& nums) {
      int n = nums.size();
      stack<int> st1,st2;
      vector<int> preGreater(n,INT_MIN);
      vector<int> nextSmaller(n,INT_MAX);

      st1.push(nums[0]);
      for(int i = 1; i < nums.size(); ++i){
        if(nums[i] > st1.top()) {
          st1.push(nums[i]);
        } else {
          preGreater[i] = st1.top();
        }
      }
      
      st2.push(nums.back());
      for(int i = nums.size()-2; i >= 0; --i) {
        if(nums[i] < st2.top()) {
          st2.push(nums[i]);
        } else {
          nextSmaller[i] = st2.top();
        }
      }

      int res = 0;
      for(int i = 0; i < nums.size(); i++) {
        if(preGreater[i] == INT_MIN && nextSmaller[i] == INT_MAX) {
          res++;
        }
      }
      return res;
    }
    
};


/*
if num have previous greater || next smaller the number can't be found


question 
1. is the num unique?

*/