class Solution {
public:
    // bool increasingTriplet(vector<int>& nums) {
    //   int n = nums.size();
      
    //   vector<bool> leftSmaller(n,false);
    //   stack<int> st;

    //   for (int i = 0; i < n; i++) {
    //     while (!st.empty() && nums[i] <= st.top()) {
    //       st.pop();
    //     }
    //     if (st.empty()) {
    //       leftSmaller[i] = false;
    //     } else {
    //       leftSmaller[i] = true;
    //     }
    //     st.push(nums[i]);
    //   }
      
    //   stack<int> st2;
    //   for (int i = n - 1; i >= 0; --i) {
    //     while (!st2.empty() && nums[i] >= st2.top()) {
    //      st2.pop();
    //     }
    //     if (st2.empty() || !leftSmaller[i]) {
    //       st2.push(nums[i]);
    //       continue;
    //     } else {
    //       return true;
    //     }
    //   }
    //   return false; 
    // }
    bool increasingTriplet(vector<int>& nums) {
      int first = INT_MAX, second = INT_MAX;
      for (auto& n : nums) {
        if (n < first) {
          first = n;
        } else if ( n > first && n < second) {
          second = n;
        } else if (n > first && n > second) {
          return true;
        }
      }
      return false;
    }
};

/*
find left smaller 
find right larger


*/