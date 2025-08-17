class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
      int n = expression.size();
      vector<int> nums;
      vector<char> op;

      int i = 0;
      while (i < n) {
        if (isdigit(expression[i])) {
          int num = expression[i] - '0';
          if (i+1 < n && isdigit(expression[i+1])) {
            i++;
            num *= 10;
            num += expression[i] - '0';
          }
          nums.push_back(num);
        } else {
          op.push_back(expression[i]);
        }
        i++;
      }
      int m = op.size();
      if (m == 0) return nums;
      vector<vector<vector<int>>> memo(m,vector<vector<int>>(m));
      return dfs(0, m-1, nums, op, memo);
    }

    vector<int> dfs(int left, int right, vector<int>& nums, vector<char>& op,vector<vector<vector<int>>>& memo) {
      if (memo[left][right].size() != 0) {
        return memo[left][right];
      }
      if (left == right) {
        return {cal(nums[left],nums[left+1],op[left])};
      }
      vector<int> res;
      for (int i = left; i <= right; i++) {
        vector<int> leftPart;
        if (i-1 < left) {
          leftPart = {nums[left]};
        } else {
          leftPart = dfs(left, i - 1, nums, op, memo); 
        }

        vector<int> rightPart; 
        if (i+1 > right) {
          rightPart = {nums[right+1]};
        }  else {
          rightPart = dfs(i + 1, right, nums, op, memo); 
        }

        for (int& left : leftPart) {
          for (int& right : rightPart) {
            res.push_back(cal(left,right,op[i]));
          }
        }
      }
      return memo[left][right] = res;
    }

    int cal(int x, int y , char op) {
      if (op == '+') {
        return x + y;
      } else if ( op == '-' ) {
        return x - y;
      }
      return x * y;
    }
};

/*

(XXX)XXXXXXX
no 
n num / n-1 op

divided and conquear
dfs
combine
memo


1 2 3 4 5
 - - + +
*/