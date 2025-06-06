class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> res(n,0);
        stack<int> st;
        for(int i=0; i<n; i++) {
            if(st.empty() || temperatures[i]<=temperatures[st.top()] ) {
                st.push(i);
            } else {
                while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                    int index = st.top();
                    st.pop();
                    res[index] = i-index;
                }
                st.push(i);
            }
        }
        return res;
    }
};