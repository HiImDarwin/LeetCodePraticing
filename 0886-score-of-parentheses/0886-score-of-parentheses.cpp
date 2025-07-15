class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for(char element: s) {
          if(element == '(') {
            st.push(0);
          } else {
            int sum = 0;
            while(st.top() != 0) {
              sum += st.top(); st.pop();
            }
            st.pop(); // pop zero;
            if(sum == 0) {
              st.push(1);
            } else {
              st.push(2*sum);
            }
          }
        }
        int sum = 0;
        while(!st.empty()) {
          sum += st.top(); st.pop();
        }
        return sum;
    }
};


/*
case
 1.  ((())) 
        ^   1
         ^  1*2 = 2
          ^ 2*2 = 4

 2.  (()()()())
     ^^^

 if we meet '(' push 0 inside
*/