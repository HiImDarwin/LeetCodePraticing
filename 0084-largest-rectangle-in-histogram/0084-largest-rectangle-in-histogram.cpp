class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //monotonic increase
        int n = heights.size();
        int maximum = 0;
        stack<int> st;
        for(int i=0;i<n;i++) {
            if(st.empty() || heights[i]>=st.top()) {
                st.push(heights[i]);
            } else {
                maximum = max(maximum,cleanST(st,heights[i]));
                st.push(heights[i]);
            }
        }
        maximum = max(maximum,cleanST(st));
        return maximum;
    }

    int cleanST(stack<int> &st,int val=-1) {
        int maxi =0;
        int count=0;
        while(!st.empty() && st.top()>val) {
            int x = st.top();
            st.pop();
            count++;
            while(!st.empty() && st.top() == x) {
                st.pop();
                count++;
            }
            maxi = max(maxi,x*count);
        }
        if(val == -1) return maxi;
        while(count>0){
            st.push(val);
            count--;
        }
        return maxi;
    }
};