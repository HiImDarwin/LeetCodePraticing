class Solution {
public:
    int numWays(string s) {
      int n = s.length();
      unordered_map<int,int> Map;
      int M = 1e9+7;
      int count = 0;
      for(int i = 0; i < n; ++i) {
        if(s[i] == '1') {
          count++;
          Map[count] = i;
        }
      }
      if(count%3 != 0) return 0;
      if(count == 0) return (1LL*(n-1)*(n-2)/2%M);
      long x = Map[count/3 +1] - Map[count/3];
      long y = Map[count/3*2 +1] - Map[count/3*2];
      return (x*y)%M;
    }
};



/*
1. the num of 1 must be multiple of 3
2. the firt cut be between  num/3 ~ num/3+1  
3. the second cut can between  num/3*2 ~ num/3*2+1  

cornor case
n = 0
place can be insert will be n-1
C(n-1,2)

*/