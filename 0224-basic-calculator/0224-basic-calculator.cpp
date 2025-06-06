class Solution {
public:
    int calculate(string s) {
        int res=0;
        int num=0;
        int sign =1;
        stack<int> st;

        for(int i=0; i<s.length(); ++i) {
            char c=s[i];
            if(isdigit(c)){
                num = num*10+ (c-'0');
            } else if( c=='+'||c=='-') {
                res += sign*num;
                num = 0;
                sign = (c=='-') ? -1: 1;
            } else if( c =='(') {
                st.push(res);
                st.push(sign);
                res =0;
                sign =1;
            } else if( c==')') {
                res += num*sign;
                num = 0;
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
        }
        res += sign * num;
        return res;
    }
};