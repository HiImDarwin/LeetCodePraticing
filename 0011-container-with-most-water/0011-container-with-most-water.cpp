class Solution {
public:
    // int maxArea(vector<int>& height) {
    //   int n = height.size();
    //   vector<int> postHigher(n);
    //   vector<int> preHigher(n);
    //   stack<int> st;
    //   for (int i = n - 1; i >= 0; i--) {
    //     while (!st.empty() && height[i] >= height[st.top()]) {
    //       st.pop();
    //     }
    //     postHigher[i] = st.empty() ? -1 : st.top();
    //     st.push(i);
    //   }
    //   st = stack<int>();
    //   for (int i = 0; i < n; i++) {
    //     while (!st.empty() && height[i] >= height[st.top()]) {
    //       st.pop();
    //     }
    //     preHigher[i] = st.empty() ? -1 : st.top();
    //     st.push(i);
    //   }

    //   int maxArea = 0;
    //   int front = 0;
    //   int end = n - 1;
    //   int lowerHeight = INT_MAX;
    //   int area;
    //   while (front != -1 && end != -1) {
    //     lowerHeight = min(height[front], height[end]);
    //     area = lowerHeight * (end - front);
    //     maxArea = max(maxArea, area);
    //     if (lowerHeight == height[front]) {
    //       front = postHigher[front];
    //     } else {
    //       end = preHigher[end];
    //     }
    //   }

    //   return maxArea;
    // }
    int maxArea(vector<int>& height) {
      int n = height.size();
      int front = 0;
      int end = n - 1;
      int maxArea = 0;

      while (front < end) {
        int minHeight = min(height[front], height[end]);
        maxArea = max(maxArea, minHeight * (end - front));
        if (minHeight == height[front]) {
          front++;
        } else {
          end--;
        }
      }

      return maxArea;
    }
};


/*
  two pointer n^2
  right to left ascending arrry
  left to right ascending array
  

*/