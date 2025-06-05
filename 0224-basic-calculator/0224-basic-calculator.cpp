class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int i = 0;
        int n =s.length();
        while(i < s.length()){
            char c=s[i];
            if(c == ' '){
                i++;
                continue;
            }

            if (isdigit(c) || (c == '-' && isUnaryMinus(s, i))) {
                int sign =1;
                if(c == '-') {
                    sign = -1;
                    i++;
                }
                while (i < n && s[i] == ' ') i++;
                if (i < n && isdigit(s[i])) {
                    int num = 0;
                    while(i<n && isdigit(s[i])) {
                        num = num*10+(s[i]-'0');
                        i++;
                    }
                    nums.push(sign*num);
                } else if(i < n && s[i] == '(') {
                    nums.push(0);
                    ops.push('-');
                }
                continue;
            }

            if(c =='(') {
                ops.push(c);
            }else if (c == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    computeTop(nums, ops);
                }
                ops.pop(); // pop '('
            } else if(isOp(c)) {
                while(!ops.empty() && precedence(ops.top())>= precedence(c)) {
                    computeTop(nums,ops);
                }
                ops.push(c);
            }
            i++;
        }
        while (!ops.empty()) {
            computeTop(nums, ops);
        }

        return nums.top();
           

    }
private:
    bool isOp(char c) {
        return c == '+' || c == '-' || c == '*';
    }

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*') return 2;
        return 0;
    }

    void computeTop(stack<int>& nums, stack<char>& ops) {
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        nums.push(applyOp(a, b, op));
    }

    int applyOp(int a, int b, char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        return 0;
    }
    bool isUnaryMinus(const string& s, int i) {
        
        if (i == 0) return true;

       
        int j = i - 1;
        while (j >= 0 && s[j] == ' ') j--;

        return (j < 0 || s[j] == '(' || isOp(s[j]));
    }
};