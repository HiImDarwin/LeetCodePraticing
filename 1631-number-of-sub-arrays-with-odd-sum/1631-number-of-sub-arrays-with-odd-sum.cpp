class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
      vector<int> vec(2,0);
      vec[0]++; //becasue 0 is odd
      int sum = 0;
      int res = 0;
      int M = 1e9 +7;
      for(int i = 0; i< arr.size(); ++i) {
        sum += arr[i];
        res += (sum % 2 == 1) ? vec[0] : vec[1];
        res %= M;
        vec[sum%2]++;
      }
      return res;      
    }
};


/*





1. array length
2. array val range
3. 

*/