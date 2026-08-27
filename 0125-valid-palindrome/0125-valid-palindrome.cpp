class Solution {
public:
    bool isPalindrome(string s) {
      int end = s.length() - 1;
      int front = 0;

      while(front < end) {
        while(front < end && !isalnum(s[front])) {
          front++;
        }
        while(front < end && !isalnum(s[end])) {
          end--;
        }
        if (tolower(s[front]) != tolower(s[end])) {
          return false;
        }
        front++;
        end--;
      }

      return true;
    }
};