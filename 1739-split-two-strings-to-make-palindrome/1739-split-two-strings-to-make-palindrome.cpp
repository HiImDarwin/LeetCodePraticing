class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
      return check(a,b) || check(b,a);
    }

    bool check(string a, string b) {
      int n = a.length();
      int left = 0, right = n-1;
      bool res = false;
      while (left < right && a[left] == b[right]) {
        left++;
        right--;
      }
      if (left > right) {
        res = true;
      } else {
        res |= isPalindrome(a.substr(left, right- left + 1));
        res |= isPalindrome(b.substr(left, right- left + 1));
      } 
      return res;
    }

    bool isPalindrome(string str) {
      int left = 0,right = str.length()-1;
      while (left < right) {
        if (str[left] != str[right]) {
          return false;
        }
        left++;
        right--;
      }
      return true;
    }
};


/*

X X X X X | X X X X X 
    aPre.     aSuf   
X X X X X | X X X X X  
    bPre.     bSuf


apre[0] = bSuf[m-1]
*/