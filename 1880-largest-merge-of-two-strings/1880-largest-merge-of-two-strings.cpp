class Solution {
public:
    string largestMerge(string word1, string word2) {
      int i = 0, j = 0;
      string res;
      while (i < word1.length() && j < word2.length()) {
        if (greaterSuffix(word1, i, word2, j)) {
          res.push_back(word1[i++]);
        } else {
          res.push_back(word2[j++]);
        }
      }
      if (i < word1.size()) res += word1.substr(i);
      if (j < word2.size()) res += word2.substr(j);
      return res;
    }
  private:
    bool greaterSuffix(const string& a, int i,
                  const string& b, int j) {
      int m = a.size(), n = b.size();
      while (i < m && j < n && a[i] == b[j]) {
        i++;
        j++;
      }
      return j == n || (i < m && a[i] > b[j]);
    }
};

/*
XXXXXXOOO
XXXOOOOOO

faster find greater element
dp[k][i] = max dp[k-1][k-1:0] + num2[]
dp[1][0] = dp[0][0] + word2[0]
dp[1][1] = dp[0][0] + word1[0]




idx1 = i - 1
idx2 = k - i - 1;

dp[2][0] = dp[1][0] + word2[1] 
dp[2][1] = dp[1][0] + word1[1], dp[1][1] + word2[0]
dp[2][2] = dp[1][1] + word[1]


*/