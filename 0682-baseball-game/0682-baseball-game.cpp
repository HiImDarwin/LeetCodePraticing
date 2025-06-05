class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int num;
        for(string& s: operations) {
            if(s == "D") {
                num = st.top()*2;
                st.push(num);

            } else if (s =="C") {
                if(!st.empty()) st.pop();

            } else if (s == "+") {
                int num2 = 0;
                num = 0;
                if(st.empty()) {
                    st.push(num);
                    continue;
                } else if(!st.empty()) {
                    num = st.top();
                    st.pop();
                    if(!st.empty()) num2 =st.top();
                    st.push(num);
                    st.push(num+num2);
                }
            } else {
                int num = stoi(s);
                st.push(num);
            }
        }
        num = 0;
        while(!st.empty()) {
            num += st.top();
            st.pop();
        }
        return num;
        
    }
};