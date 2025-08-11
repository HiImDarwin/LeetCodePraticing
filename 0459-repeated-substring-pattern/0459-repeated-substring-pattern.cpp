class Solution 
{
  public:
    bool repeatedSubstringPattern(string s) 
    {
      int n = s.length();
      vector<int> lps(n,0);
      int len = 0;
      for (int i = 1; i < n; ++i) {
        while (len > 0 && s[i] != s[len]) {
          len = lps[len-1];
        }
        if (s[i] == s[len]) {
          len++;
        }
        lps[i] = len;
      }
      int k = lps[n-1];
      return (k >0 && n%(n - k) == 0);
    }
};
/*


s1: * * * * * * * * * [x x x]
   0                      
s2:[x x x] * * * * * * * * * 
                          n-1
假設 dp[n-1] = 9 因此現在 s1[0:8] = s2[3:11]
因為 s1 其實就是 s2 現在 s1 後綴剩三個數值
然後因為 s1[0:8] = s2[3:11] 因此可以得知 s1[6:8] = s2[9:11]
s1: [* * * ][* * *][* * *][x x x]
   0             | | |  | | |    
s2:[x x x] * * * * * *  * * * 

if the
1.  lps[n-1] > 0 and 
2. remaining *** length is divisiable by lps[n-1]
3. for each index j =  n-1 - lps[n-1]*k : lps[j] == lps[n-1]

then the substring can combine the string

*/