class Solution {
  string s1,s2;
  vector<vector<vector<int>>> memo;

public:
    bool isScramble(string s1, string s2) {
      int len = s1.length();
      this->s1 = s1;
      this->s2 = s2;
      memo.resize(len,vector<vector<int>>(len,vector<int>(len+1,-1)));
      return Recursive(0, len-1, 0, len-1);
    }

    bool Recursive(int left1, int right1, int left2, int right2) {
      int len = right1 - left1 + 1;
      if (memo[left1][left2][len] != -1) {
        return memo[left1][left2][len];
      }
      if (left1 == right1) {
        return s1[left1] == s2[left2];
      } 
      // X XXXXX
      for (int i = 1; i < len; i++) {
        bool lPart,rPart;
        if (Recursive(left1, left1 + i - 1, left2, left2 + i - 1) && 
            Recursive(left1 + i, right1, left2 + i, right2)) {
          memo[left1][left2][len] = 1;
          return true;
        }
        if (Recursive(left1, left1 + i - 1, right2 - i + 1, right2) && 
            Recursive(left1 + i, right1, left2, right2 - i)) {
          memo[left1][left2][len] = 1;
          return true;
        }
      }
      memo[left1][left2][len] = 0;
      return false;
    }
};


/*
divide and conquear

dp
XXXX XXXXX   s2 YYYYYYYY
    ^


if (left == right) {

}

for (int i = left; i < right i++) {
  bool left
  bool right
  if (left && right) return true;
  //swap
  bool left =
  bool right =
  
}
return false;







*/