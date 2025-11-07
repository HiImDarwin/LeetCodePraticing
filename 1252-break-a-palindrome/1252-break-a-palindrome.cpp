class Solution {
public:
    string breakPalindrome(string palindrome) {
      int len = palindrome.length();
      if (len == 1) {
        return "";
      }
      bool change = false;
      for (int i = 0; i < len; i++) {
        if (palindrome[i] == 'a' || (len % 2 == 1) && (i == len / 2)) {
          continue;
        }
        palindrome[i] = 'a';
        change = true;
        break;
      }
      if (!change) {
       palindrome[len - 1]++; 
      }
      return palindrome;
    }
};