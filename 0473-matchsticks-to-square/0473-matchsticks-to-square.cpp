class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
      long long total = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
      if (total % 4 != 0) {
        return false;
      }
      edgeLength_ = total / 4;

      sort(matchsticks.rbegin(), matchsticks.rend());
      int n = matchsticks.size();
      targetMask_ = (1 << n) - 1;
      memo_.clear();
      return recursive(matchsticks, 0, 0, 0);
    }

private:
    bool recursive(vector<int>& matchsticks, int mask, int round, long long sum) {
      if (round == 3) {
        return true;
      }
      if (memo_.count(mask)) {
        return memo_[mask];
      }

      int n = matchsticks.size();

      for (int i = 0; i < n; i++) {
        if (((1 << i) & mask)) {
          continue;
        }

        long long newSum = sum + matchsticks[i];
        if (newSum > edgeLength_) {
          continue;
        }

        int newMask = mask | (1 << i);
        int newRound = round;
        if (newSum == edgeLength_) {
          newRound++;
          newSum = 0;
        }

        if (recursive(matchsticks, newMask, newRound, newSum)) {
          return true;
        } 
      }
      return memo_[mask] = false;
    }

    int targetMask_;
    long long edgeLength_;
    unordered_map<int, bool> memo_;
};

/*
[5,5,5,5,4,4,4,4]
bit mask if sum = x and bit avaliable  = 0000111111 can't than x 0000000111 can't too
00000111
00011111
if the exist condition 0 cover all my zero than  it's not possiable to generate anser
*/