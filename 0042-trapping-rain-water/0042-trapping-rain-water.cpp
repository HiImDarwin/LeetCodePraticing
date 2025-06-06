class Solution {
public:
    int trap(vector<int>& height) {

        //find right higher(or eaqual)
        //find right lower
        int n = height.size();
        int res=0;
        stack<int> st;

        for(int i=0; i<n; ++i) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int bottom = st.top();
                st.pop();

                if(st.empty()) break;

                int left = st.top();
                int width = i-left-1;
                int h = min(height[i],height[left]) - height[bottom];

                res += width*h;
            }
            st.push(i);
        }
        
        return res;
    }
};