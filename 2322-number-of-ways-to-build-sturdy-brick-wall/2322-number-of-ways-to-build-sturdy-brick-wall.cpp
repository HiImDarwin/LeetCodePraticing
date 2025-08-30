class Solution {
public:
    int buildWall(int height, int width, vector<int>& bricks) {
      unordered_set<int> widthSet(bricks.begin(), bricks.end());
      vector<int> patterns = BuildPattern(width, widthSet);
      return CountWays(height, patterns);  
    }

    int CountWays(const int height, vector<int>& pattern) {
      int MOD = 1e9 + 7;

      vector<vector<int>> dp(height,vector<int>(pattern.size(),0));
      for (int i = 0; i < pattern.size(); i++) {       
          dp[0][i] = 1;
      }

      for (int i = 1 ; i < height; i++) {
        for (int state = 0; state < pattern.size(); state++) {
          for (int prevState = 0; prevState < pattern.size(); prevState++) {
            if (!(pattern[state] & pattern[prevState])) {
              dp[i][state] = (dp[i][state] + dp[i - 1][prevState]) % MOD;
            }
          }
        }
      }
      int sum = 0;
      for (int i = 0 ; i < pattern.size(); ++i) {
        sum = (sum + dp[height - 1][i]) % MOD;
      }

      return sum;    
    }

    vector<int> BuildPattern(const int width, unordered_set<int>& widthSet) {
      int m = width - 1;
      vector<int> pattern;
      for (int i = 0; i < (1 << m); ++i) {
        vector<int> tmp;
        tmp.push_back(-1);
        for (int j = 0; j <= m; ++j) {
          if ((i >> j) & 1) {
            tmp.push_back(j);
          }
        }
        tmp.push_back(m);

        bool valid = true;     
        for (int i = 0; i < tmp.size()-1; ++i) {
          int width = tmp[i + 1] - tmp[i];
          if (widthSet.find(width) == widthSet.end()) {
            valid = false;
            break;
          }
        }
        if (valid) {
          pattern.push_back(i);
        }
      }
      return pattern;
    }
};


/*
we need all status
all bricks value is unique
all permutation need to be test
n bricks 
n!
find all length sum == width
status XOR if 

XXX XXX XXX XXX 
XXX XXX XXX XXX

過往都是01表示物件是否使用
這題比較特別 因為排列可能太多了 應該去想怎麼切割
長度7的牆 有6個位置可以切 對應的是切割點

相臨城牆XOR < (1<<n - 1) 就不行 (& > 0 也可以)

dp[i][state] += !(state & otherstate) ? dp[i - 1][otherstate] : 0;

*/