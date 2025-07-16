class Solution {
public:
    // int validSubarrays(vector<int>& nums) {
    //   nums.push_back(INT_MIN);
    //   stack<int> st;
    //   int count = 0;
    //   for(int i = 0; i < nums.size(); ++i) {
    //     while (!st.empty() && nums[i] < nums[st.top()]) {
    //       count += i - st.top();
    //       st.pop();
    //     }
    //     st.push(i);
    //   }
    //   return count;
    // }
    int validSubarrays(vector<int>& nums) {
      stack<int> indexSt;
      int count = 0;
      for(int i = nums.size()-1; i >= 0; i--) {
        while(!indexSt.empty() && nums[i] <= nums[indexSt.top()]) {
          indexSt.pop();
        }
        if(indexSt.empty()) {
          count += nums.size()-i;
        } else {
          count += indexSt.top() - i;
        }
        indexSt.push(i);
      }
      return count;
    }
      
};


/*
  find next smaller element;


*/