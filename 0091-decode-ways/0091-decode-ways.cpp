class Solution {
public:
    // int numDecodings(string s) {
    //     if(s.length() == 0 or s[0] == '0') return 0;
    //     //F[n] = F[n-1]+F[n-2]
    //     vector<int> decode_way(s.length()+1,0);
    //     decode_way[0]=1; // node num is an decode way too
    //     decode_way[1]=1;

    //     for(int i=2; i< s.length()+1;i++){
    //         if(s[i-2] == '0' && s[i-1] == '0') break;
    //         if(s[i-1] != '0') decode_way[i] += decode_way[i-1];
    //         if(s[i-2] == '1' ||( s[i-2] == '2' && s[i-1]<'7')) decode_way[i] += decode_way[i-2];
    //     }
    //     return decode_way[s.length()];
    // }
    int numDecodings(string s) {
      if (s[0] == '0') return 0;
      int n = s.length();
      int prev1 = 1, prev2 = 1;

      for (int i = 1; i < n; i++) {

        int curr = (s[i] == '0') ? 0 : prev1;
        if ( s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6' && s[i] >= '0') ) {
          curr += prev2;
        } else if (s[i] == '0' && (s[i - 1] != '1' && s[i - 1] != '2')) {
          return 0;
        }
        prev2 = prev1;
        prev1 = curr;
      }
      
      return prev1;
    }

    /*
      if s[i] == '0' check s[i-1]
        dp[i] = dp[i-1];
      if (s[i] == other)
        dp[i] = dp[i-1] + s[i-1] == 1 || 2
        dp[i] += dp[i-1];
      


      Edge case
      s[0] == '0'

    */
};