class Solution {
public:
    // vector<int> dailyTemperatures(vector<int>& temperatures) {

    //     int n = temperatures.size();
    //     vector<int> res(n,0);
    //     stack<int> st;
    //     for(int i=0; i<n; i++) {
    //         if(st.empty() || temperatures[i]<=temperatures[st.top()] ) {
    //             st.push(i);
    //         } else {
    //             while(!st.empty() && temperatures[st.top()] < temperatures[i]){
    //                 int index = st.top();
    //                 st.pop();
    //                 res[index] = i-index;
    //             }
    //             st.push(i);
    //         }
    //     }
    //     return res;
    // }

    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        vector<int> st, ans(n, 0);
        for(int i=n-1; i>=0; i--){
            while(st.size() && arr[st.back()]<=arr[i])
                st.pop_back();
            if(st.size()){
                ans[i]=st.back()-i;
            }
            st.push_back(i);
        }
        return ans;
    }
};