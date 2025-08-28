class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
      sort(tokens.begin(), tokens.end());
      int preSum = 0, postSum = 0;
      int i = 0, j = tokens.size() - 1;
      int score = 0;
      int res = 0;
      while (i <= j) {
        if (power >= tokens[i]) {
          power -= tokens[i];
          score++;
          i++;
          res = max(res, score);
        } else {
          if (score == 0) {
            break;
          }
          power += tokens[j];
          j--;
          score--;
          
        }
      }
      return res;
    }
};


/*

init = 0;
1 2 4 5 6 8
i         j
i       j
      i j    power = 1
      
*/