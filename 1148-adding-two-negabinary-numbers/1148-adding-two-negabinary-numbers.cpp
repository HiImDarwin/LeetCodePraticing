class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
      int m = arr1.size();
      int n = arr2.size();
      int idx1 = m-1, idx2 = n-1;
      int carry = 0;
      vector<int> res;
      while (idx1 >= 0 || idx2 >= 0 || carry) {
        int total = carry;
        total += idx1 >= 0 ? arr1[idx1] : 0;
        total += idx2 >= 0 ? arr2[idx2] : 0;
        
        int r = total%(-2);
        carry = total/(-2);
        
        if (r<0) {
          if (carry > 0) {
            carry--;
          } else {
            carry++;
          }
          r += abs(2);
        }

        res.push_back(r);
        idx1--;
        idx2--;
      }
      int i = res.size()-1;
      while (res[i] == 0 && i > 0) {
        res.pop_back();
        i--;
      }
      reverse(res.begin(), res.end());
      return res;
    }
};


/*
for the power of even num will be positive
power of odd will be negative

if postive i got two 1 the  


  1 1 0 1
    0 0 1
       
*/
