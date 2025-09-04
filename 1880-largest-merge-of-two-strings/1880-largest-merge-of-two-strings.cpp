class Solution {
public:
    string largestMerge(string word1, string word2) {
      if (word1.size() == 0 || word2.size() == 0) {
        return word1 + word2;
      }
      if (word1 > word2) {
        return word1[0] + largestMerge(word1.substr(1), word2);
      } else {
        return word2[0] + largestMerge(word1, word2.substr(1));
      }
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