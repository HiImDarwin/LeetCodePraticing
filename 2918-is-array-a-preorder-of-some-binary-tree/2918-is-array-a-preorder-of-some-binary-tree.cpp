class Solution {
public:
    bool isPreorder(vector<vector<int>>& nodes) {
      stack<int> st;
      st.push(-1);
      for(auto node : nodes) {
        int id = node[0];
        int parentId = node[1];
        while(!st.empty() && st.top() != parentId) {
          st.pop();
        }
        if(st.empty()) return false;
        st.push(id);
      }
      return true;
    }
};


/*
preorder traversal > so that root left right
so  for each node their root will show befor them

*/