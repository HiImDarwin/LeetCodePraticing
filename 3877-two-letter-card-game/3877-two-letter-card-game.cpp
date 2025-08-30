class Solution {
      int getPairs(int total, int largestGroup) {
        if (total <= 1) return 0;
        return min(total / 2, total - largestGroup);
      }
public:
    int score(vector<string>& cards, char x) {
      unordered_map<char,int> leftX, rightX;
      int doubleX = 0;
      
      for (auto& card : cards) {
        if (card[0] == x && card[1] == x) {
          doubleX++;
        } else if (card[0] == x) {
          leftX[card[1]]++;
        } else if (card[1] == x) {
          rightX[card[0]]++;
        }
      }
      int res = 0;

      int leftMost = 0, leftCount = 0;
      for (auto& [c, count]: leftX) {
        leftMost = max(leftMost, count);
        leftCount += count;
      }

      int rightMost = 0, rightCount = 0;
      for (auto& [c, count] : rightX) {
        rightMost = max(rightMost, count);
        rightCount += count;
      }
      
      for (int left = 0 ;left <= doubleX; left++) {
        int right = doubleX - left;
        int max1 = max(leftMost, left);
        int max2 = max(rightMost, right);
        int score1 = getPairs(leftCount + left, max1);
        int score2 = getPairs(rightCount + right, max2);
        res = max(res, score1 + score2);
      }
      
      return res;
    }
};


/*

trie

count aa
count a* 
count *a
給左邊1 右邊k-1 

*/