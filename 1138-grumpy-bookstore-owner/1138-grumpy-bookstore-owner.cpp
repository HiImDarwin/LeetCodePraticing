class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int count = 0;
        int res = 0;
        int total = 0;
        for(int i = 0; i < n; ++i) {
          if(grumpy[i] == 1) {
            count += customers[i]; 
          } else {
            total += customers[i];
          }
          if(i - minutes >= 0 && grumpy[i-minutes] == 1) {
            count -= customers[i-minutes];
          }
          res = max(res,count);
        }

        return total + res;
    }
};


/* 

The target is let and customer num in gurmpy min maximiz overlap with minutes
sliding window is the minutes
check the maximum of customer in window that is in grumpy min

window is fixed
right is for enter the window i
left is for exist the window i-minutes


*/