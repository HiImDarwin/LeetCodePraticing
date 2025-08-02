class Solution {
public:
    int distinctEchoSubstrings(string text) {
      int n = text.length();
      text = "#" + text;
      auto dp = vector<vector<int>>(n+1,vector<int>(n+1,0));
      dp[0][0] = 0;
      unordered_set<string> Set;

      for (int i = 0; i <=n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
          if (text[i] == text[j]) {
            dp[i][j] = dp[i-1][j-1] + 1;
          }
          if (dp[i][j] >= j-i) { //this means two substring in concatenation 
            string str = text.substr(i + 1, j - i);
            Set.insert(str);
          }
        }
      }
      return Set.size();
    }
};

        
/*
dp[i][j]

i means start index 
j means substrin half length
dp[i] = dp[]
"abcabcabc"



*/