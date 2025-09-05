class Solution {
public:
    // int distinctEchoSubstrings(string text) {
    //   int n = text.length();
    //   text = "#" + text;
    //   auto dp = vector<vector<int>>(n+1,vector<int>(n+1,0));
    //   dp[0][0] = 0;
    //   unordered_set<string> Set;

    //   for (int i = 0; i <=n; ++i) {
    //     for (int j = i + 1; j <= n; ++j) {
    //       if (text[i] == text[j]) {
    //         dp[i][j] = dp[i-1][j-1] + 1;
    //       }
    //       if (dp[i][j] >= j-i) { //this means two substring in concatenation 
    //         string str = text.substr(i + 1, j - i);
    //         Set.insert(str);
    //       }
    //     }
    //   }
    //   return Set.size();
    // }

    int distinctEchoSubstrings(string text) {
      unordered_set<string> res;
      for(int i = 1; i <= text.length() / 2; i++) {
        int len = 0;
        for(int left = 0, right = i; right < text.length(); left++,right++) {
          if (text[left] == text[right]) {
            len++;
          } else {
            len = 0;
          }
          if (len == i) {
            res.insert(text.substr(left,i));
            len--;
          }
        }
      }

      return res.size();
    }
};

        
/*



*/